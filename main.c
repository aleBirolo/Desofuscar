#include "main.h"

int main()
{
    char linea[TAM_LINEA]={},
         *ini,
         *fin,
         correcion[]={"acefhijklo"};
    int offset = 3;

    printf ("\n Sequencia a desofuscar: "
            "\n  a-> f "
            "\n  c-> h"
            "\n  e-> i"
            "\n  f-> j"
            "\n  h-> k"
            "\n  i-> l"
            "\n  j-> o"
            "\n  k-> a"
            "\n  l-> c"
            "\n  o-> e\n"
            );

    strcpy (linea, "jN jmot k sji sorjdknodrj; ji ouq jmot so omrkdouq nes sjiio. lkksI vjmesA");

    printf ("\n Linea original: \n |%s|\n", linea);

    /// Volteo
    ini=linea;
    fin=strchr(linea,' ');

    while ( fin && *ini )
    {
        voltear(ini, fin);
        ini=++fin ;
        fin=strchr(ini,' ');
    }

    /// Volteo la ultima palabra
    fin=strchr(ini,'\0');
    voltear(ini, fin);

    printf ("\n Linea con palabras invertidas: \n |%s|\n", linea);

    /// Desofusco
    desofuscar(linea, correcion, offset);
    printf ("\n Linea desofuscada: \n |%s|\n", linea);

    return 0;
}

char *voltear (char *ini, char *fin)
{
    char *linea=ini;
    char aux;

    fin--;
    while (ini < fin)
    {
        /// Los caracteres especiales no se reubican
        if ( ! ES_LETRA(*ini))
            ++ini;

        if (! ES_LETRA(*fin))
            --fin;

        aux=*ini;
        *ini=*fin;
        *fin=aux;

        ini++;
        fin--;
    }
    return linea;
}

char *desofuscar (char *linea, const char *correcion, int offset)
{
    char *aux=linea;
    char *pos;
    int  tam = strlen(correcion),
         auxOffset = offset;

    while (*linea)
    {
        offset = auxOffset;
        pos = strchr(correcion, *linea);

        if ( pos )
        {
            if (pos - correcion < tam - offset)
                *linea=  *( pos + offset);
            else
            {
                offset -= ( tam - (int) (pos - correcion));
                *linea = *(correcion + offset);
            }
        }
        linea++;
    }

    return aux;
}
