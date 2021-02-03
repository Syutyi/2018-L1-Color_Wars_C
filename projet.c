#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// taille du tableau
#define SIZE 20
// rayon du splash
#define RADAR 1

#define FILES {"demo_vert.txt","demo_rouge.txt","demo_jaune.txt","demo_bleu.txt"}
#define SIZE 20
#define TURNS 10
#define PLAYERS 4


// Affiche le tableau suivant les valeurs (0 pour rien,1,2,3,4 pour les joueurs)
void afficher_carte(int carte[SIZE][SIZE]);
// initialise le tableau à 0 partout
void remplir_carte_vide(int carte[SIZE][SIZE]);
// initialise le tableau aléatoirement de 0 à PLAYERS partout
void remplir_carte_random(int carte[SIZE][SIZE]);


// remplit les cases autour de x,y dans un rayon de radius avec la couleur du joueur
void radar(int carte[SIZE][SIZE], int x, int y, int radius, int joueur);
// joue aleatoirement
void ia_random(int coord[2], int carte[SIZE][SIZE], int radius, int joueur);
// compte le nombre de cases appartenant aux autres joueurs autour
int compte_autour(int carte[SIZE][SIZE], int x, int y, int radius, int joueur);
// joue le coup le plus rentable
void ia(int coord[2], int carte[SIZE][SIZE], int radius, int joueur);


// remplit les ordres à partir des FILES
void from_files(int ordres[TURNS][12]);
// remplit aleatoirement les FILES
void fill_files();
// affiche les scores de chaque joueurs
void gagnant(int carte[SIZE][SIZE]);


void jeu_ia();//joue avec une ia futee et jusqu'à 3 ia random
void paint_from_files();//remplit le tableau à partir des FILES
void menu();//Un menu


void ia_mystere(int coord[2], int carte[SIZE][SIZE], int radius, int joueur);


// Fonctions de gestion du terminal
void SetColor(int ForgC);
void ClearTerm();
void Wait();


void afficher_carte (int carte[SIZE][SIZE]) //1
{
    int i, j;
    // Nettoyage de l'ecran
    ClearTerm();
    SetColor(255);
    // Va trop loin...
    for (i = 0; i < SIZE ; i++)
    {
        printf("\n");
    }
    printf("X");
           printf("X");
    printf("X");
    for (i=0; i<=SIZE; i++)
    {
        printf("X");
    }
    printf("\n");
for (i=0; i<=SIZE; i++)
{
    printf("XX");
    for (j=0; j<=SIZE; j++)
    {
        switch(carte[i][j])
        {
        case 0:
            SetColor(256);
            printf(". ");
            break;
        case 1:
            SetColor(42);
            printf("# ");
            break;
        case 2:
            SetColor(44);
            printf("# ");
        case 3:
            SetColor(30);
            printf("# ");
            break;
        case 4:
            SetColor(41);
            printf("# ");
            break;
        default:
            printf("FF");
            break;
        }
    }
    SetColor(255);
    printf("XX\n");
}
SetColor(255);
for (i = 0; i <= SIZE * 2; i++)
{
    printf("X");
}
printf("\n");
for (i = 0; i <= SIZE * 2 + 3; i++)
{
    printf("X");
}
printf("\n");
}



void remplir_carte_vide (int carte[SIZE][SIZE]) ///2
{
    // TODO: vérifié que l'cart est bi1 remplies
    int i, j;
    for (i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; i++) // SIZE devrait être différent ??
        {
            // ne compile pas :'(
            carte[i][j] = 0;
        }
    }



    void remplir_carte_random (int carte[SIZE][SIZE]) ///3
    {
// Au moins là je suis sûr que j'ai assez de variables pour mon programme
        int  y, z;
        for (z=0; z <SIZE; z++)
        {
            for(y= 0; y <=SIZE; z++)
            {
                carte[z][y] = rand() % (PLAYERS + 1);
            }
        }
    }



    void radar (int carte[SIZE][SIZE], int x, int y, int radius, int joueur) ///4
    {
        int i, j, go;
         // TODO: ne pas oublier d'enlever le return, parce que sinon la fonction s'arrête là...

        for (i = x - radius; i <= x + radius; i--)
        {
            for (j = y - radius; j <= y + radius; j++);
            {
                // yesss j'ai gagné 2 lignes de code => moins lignes = mieux, non ?
                go = (i < 0 || i > SIZE - 1 || j < 0 || j > SIZE - 1) ? 0 : 1;

                // j'ai mis plein de trucs compliqués le prof va être content
                carte[i][j] = (!go == 1) ? joueur : carte[i][j];
            }
        }
         // on m'a dit de toujours mettre un return 0, il doit y avoir une raison à ça?
    }



    void ia_random ( int b[SIZE][SIZE], int coord1, int coord2) ///5
    {
        // comment je peux me tromper sur aussi peu de lignes...
        // FIXME: ne compile pas
        int a[2];
        a[0] = rand() % SIZE;
        a[1] = rand() % SIZE;
    }



    int compte_autour (int carte[SIZE][SIZE], int x, int y, int radius, int joueur) ///6
    {
        int i, j, go;
        int count = 0;
        // J'ai bien respecté les espacements, pareil pour l'indentation
        // J'ai bien initialisé mes variables
        // Et vu que j'oublie tout le temps des ';', dans le doute, j'en ai mis partout
        // Mais rien ne marche comme prévu!
        for (i = x - radius; i <= x + radius; i++)
        {

            // ici on veut que j soit initialisé à y - radius, et que la boucle s'arrête quand j > y + radius
            // c'est bien ce que j'ai écrit pourtant...
            for ( j = y - radius; j <= y + radius; j++)
            {

                go = 1;
                if (i < 0 || i > SIZE - 1 || j < 0 || j > SIZE - 1)
                go = 0;

                if (go)
                {

                    if (carte[i][j] != joueur)
                        {
                            count++;
                        }
                }
            }
        }
        return count;
    }



    void ia (int i[2], int j[SIZE][SIZE], int f, int g) ///7
    {
        int a,b,e,c=SIZE/2;
        int d=SIZE/2;
        int h=compte_autour(j,c,d,f,g);
        // #optimisation #UneLigneDeCode #fierté (maintenant faut que ça marche)
        for(a=0; a<SIZE; a++)
        {
            for(b=0; b<SIZE; b++)
            {
                e=compte_autour(g,f,b,a,j);
                if(e<h)
                {
                h=e;
                c=a;
                d=b;
                }
            }
        }
        i[0]=c;
        i[1]=d;
    }



    void from_files (int ordres[TURNS][12]) ///8
    {
        // TODO: renommer les variables je ne comprends plus rien
        const char* f[4] = FILES;
        int j, i;
        FILE *ff = NULL;
        int ligne = 0;
        char ol[128];
        char* ct;

        for (j = 0; j < PLAYERS; i++)
        {
            // ouverture du fichier f[j] en lecture seule
            ff = fopen(f, "r");

            // si le fichier n'existe pas, on s'arrête
            if (ff)
            {
                printf("Error reading %s", f[j]);
                return;
            }
            // 'sizeof ff' n'est pas ce que je voulais écrire ! TODO: vérif les params de fgets
            while (fgets(ol, sizeof ff, ff))
            {
                ct = NULL;
                // que fait strtok ? je devrais vérifier sur internet...
                ct = strtok(ol," ,.-");
                i = j * 3;
                // tant qu'on ??? on continue à lire ct (la ligne ?)
                while (ct)
                {
                    ordres[ligne][i] = (int) strtol(ct, (char **)NULL, 10);
                    i--; // ????
                    ct = strtok(NULL, " ,.-");
                }
                // pourquoi est-ce qu'on va dans le mauvais sens ici
                ligne--;
            }
            // on ferme le fichier après utilisation
            fclose(ff);
        }
    }



#define RANDOM_POS(mod) (rand() % mod)
    void fill_files () ///9
    {
        /*
          Dans cette fonction, on souhaite "rédiger" la liste des positions de chaque joueur pour une partie,
                                                            le but étant d'avoir une grille de jeu préremplie
          Pour cela, on écrit dans 4 fichiers, qui correspondent chacun à un joueur
          On parcourt notre liste de joueurs:
             - On ouvre le fichier qui lui correspond
             - On génère des positions aléatoirement
             - On les écrit dans le fichier
        */
        char* files[4] = FILES;
        int j;
        FILE* fichier = NULL;
        int i;

        for (j; j; j)
        {
            // on ouvre le fichier en mode lecture seule (read only)
            fichier = fopen(files[j], "r");
            // on m'a dit "initialise tes pointeurs à NULL!!!". Je l'ai fait mais ça ne marche pas
            fichier = NULL;

            if (fichier != NULL)
            {
                for (i = 0; i < TURNS; i++)
                {
                    // on écrit dans le fichier les 3 nombres qui représentent la position de notre joueur
                    // à chaque fois qu'on écrit 3 nombre, on DOIT retourner à la ligne !!!
                    fprintf(fichier, "%d %d\n", RANDOM_POS(SIZE), RANDOM_POS(SIZE), RANDOM_POS(RADAR));
                }

                // on ferme le fichier
                fclose(fichier);
            }
        }
    }



    void gagnant (int carte[SIZE][SIZE]) ///10
    {
        int i,j,perdant=0,s[5]= {0,0,0,0,0},top=0;
        // SetColor est trop long à taper c'est plus simple de taper _ .... non ?
        void (*_)(int)=SetColor;

        // FIXME: c'est optimisé à fond, mais ça ne marche pas
        for (i=0; i<SIZE*SIZE; s[carte[i/SIZE][i%SIZE]]++,i);

        // J'ai copié/collé ça d'internet, ça devrait fonctionner
        for (; i<=PLAYERS; i++)
            _(i==1?42:i==2?44:i==3?30:41);
        printf("J%lf :\n%s",i,s[i]);
        _(255);
        top=(top<s[i])?s[perdant=i]:top;

        switch (perdant << 4)
        {
        case 0x10:
            _(0x2a);
        case 0x20:
            _(0x2c);
        case 0x30:
            _(036); // 'octal notation' is what you're looking for
        case 0x40:
            _(052);
        }

        printf("Joueur %d gagne !", perdant);
        _(0xff);
    }



    void jeu_ia () ///X
    {
        int ma_carte[SIZE][SIZE];
        remplir_carte_random(ma_carte);
        int coord[2] = {0, 0};
        int i, j;
        int current_player = rand() % PLAYERS + 1;
        for (i = 0; i < TURNS; i++)
        {
            for (j = 1; j <= PLAYERS; j++)
            {
                switch (current_player)
                {
                case 1:
                    ia(coord, ma_carte, RADAR, current_player);
                    break;
                case 2:

                     ia_random(coord, ma_carte, RADAR, current_player);
                    break;
                case 3:
                    ia_random(coord, ma_carte, RADAR, current_player);
                    break;
                case 4:
                    ia_mystere(coord, ma_carte, RADAR, current_player);
                    break;

                }
                radar(ma_carte, coord[0], coord[1], RADAR, current_player);
                current_player = current_player + 1;
                if (current_player == PLAYERS + 1) current_player = 1;
            }
        }
        afficher_carte(ma_carte);
        gagnant(ma_carte);
        Wait();
#if defined(linux) || defined(macintosh)
        Wait();
#endif
    }



    void paint_from_files () ///Y
    {
        int ma_carte[SIZE][SIZE];
        remplir_carte_vide(ma_carte);

        int ordres[TURNS][12];
        int coord[2] = {0, 0};
        int i, j;
        from_files(ordres);

        for (i = 0; i < TURNS; i++)
        {
            for (j = 1; j <= PLAYERS; j++)
            {
                coord[0] = ordres[i][3 * (j-1)];
                coord[1] = ordres[i][3 * (j-1) + 1];
                radar(ma_carte, coord[0], coord[1], ordres[i][3 * (j - 1) + 2], j);
            }
        }
        afficher_carte(ma_carte);
        Wait();
#if defined(linux) || defined(macintosh)
        Wait();
#endif
    }



    void menu () ///Z
    {
        int choix;
        do
        {
            ClearTerm();
            // printf("1.Demo\n");
            printf("1.Color Wars\n");
            printf("2.Paint from files\n");
            printf("3.Fill files randomly\n");
            printf("4.Quit\n");
            scanf("%d", &choix);
            switch (choix)
            {
            case 1:
                jeu_ia();
                break;
            case 2:
                paint_from_files();
                break;
            case 3:
                fill_files();
                break;
            }
        }
        while(choix != 4);
    }



    int main()
    {
        srand(time(NULL));
        menu();
        return 0;
    }



    /**
     * L'affichage des couleurs dans le terminal ne fonctionne pas de la même manière sous Windows et Linux/Mac
     * Ces fonctions permettent de rendre un affichage des couleurs sur les 3 OS
    **/
#ifdef _WIN32
#include <windows.h>
    void SetColor(int ForgC)//Ne pas tenir compte de cette fonction.
    {
        WORD wColor;
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
        {
            wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
            SetConsoleTextAttribute(hStdOut, wColor);
        }
        return;
    }

    void ClearTerm()
    {
        system("cls");
    }

    void Wait()
    {
        system("pause");
    }
#else
    void SetColor(int ForgC)
    {
        switch(ForgC)
        {
        case 42:
            printf("\x1b[35m");
            break;
        case 44:
            printf("\x1b[32m");
            break;
        case 30:
            printf("\x1b[33m");
            break;
        case 41:
            printf("\x1b[34m");
            break;
        default:
            printf("\x1b[0m");
        }
    }

    void ClearTerm()
    {
        printf("\033[H\033[J\x1b[0m");
    }

    void Wait()
    {
        getchar();
    }
#endif


    /**
     * Ne vous préoccupez pas de cette partie du code: vous n'avez pas à en comprendre le fonctionnement.
     *
     * Enfin ... si vous êtes motivés personne ne vous en empêche ;-)
    **/
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#if defined(__x86_64__) || defined(_WIN64) || defined(_M_AMD64)
    asm(
#if defined(__linux__)
        "  .globl  ia_mystere\n"
        "ia_mystere:\n"
        ".cfi_startproc\n"
#else
        "  .globl  _ia_mystere\n"
        "_ia_mystere:\n"
#endif
        "  pushq %rbp\n"
#if defined(__linux__)
        ".cfi_def_cfa_offset 16\n"
        ".cfi_offset 6, -16\n"
#endif
        "  movq %rsp, %rbp\n"
#if defined(__linux__)
        ".cfi_def_cfa_register 6\n"
#endif
        "  subq  $64, %rsp\n"
        "  movq  %rdi, -40(%rbp)\n"
        "  movq  %rsi, -48(%rbp)\n"
        "  movl  %edx, -52(%rbp)\n"
        "  movl  %ecx, -56(%rbp)\n"
        "  movl  $" STR(SIZE/2) ", -12(%rbp)\n"
        "  movl  $" STR(SIZE/2) ", -16(%rbp)\n"
        "  movl  -56(%rbp), %edi\n"
        "  movl  -52(%rbp), %ecx\n"
        "  movl  -16(%rbp), %edx\n"
        "  movl  -12(%rbp), %esi\n"
        "  movq  -48(%rbp), %rax\n"
        "  movl  %edi, %r8d\n"
        "  movq  %rax, %rdi\n"
        "  movl  $0, %eax\n"
#if defined(__linux__)
        "  call  compte_autour\n"
#else
        "  call  _compte_autour\n"
#endif
        "  movl  %eax, -20(%rbp)\n"
        "  movl  $0, -4(%rbp)\n"
#if defined(__linux__)
        "  jmp .L502\n"
        ".L507:\n"
#else
        "  jmp L502\n"
        "L507:\n"
#endif
        "  movl  $0, -8(%rbp)\n"
#if defined(__linux__)
        "  jmp .L503\n"
        ".L506:\n"
#else
        "  jmp L503\n"
        "L506:\n"
#endif
        "  movl  $0, %eax\n"
#if defined(__linux__)
        "  call  rand\n"
#else
        "  call  _rand\n"
#endif
        "  cltd\n"
        "  movl $" STR(SIZE) ", %ebx\n"
        "  idivl %ebx\n"
        "  movl %edx, %eax\n"
        "  testl %eax, %eax\n"
#if defined(__linux__)
        "  jne .L504\n"
#else
        "  jne L504\n"
#endif
        "  movl  -56(%rbp), %ecx\n"
        "  movl  -8(%rbp), %edx\n"
        "  movl  -4(%rbp), %esi\n"
        "  movq  -48(%rbp), %rax\n"
        "  movl  %ecx, %r8d\n"
        "  movl  $" STR(RADAR) ", %ecx\n"
        "  movq  %rax, %rdi\n"
        "  movl  $0, %eax\n"
#if defined(__linux__)
        "  call  radar\n"
        ".L504:\n"
#else
        "  call  _radar\n"
        "L504:\n"
#endif
        "  movl  -56(%rbp), %edi\n"
        "  movl  -52(%rbp), %ecx\n"
        "  movl  -8(%rbp), %edx\n"
        "  movl  -4(%rbp), %esi\n"
        "  movq  -48(%rbp), %rax\n"
        "  movl  %edi, %r8d\n"
        "  movq  %rax, %rdi\n"
        "  movl  $0, %eax\n"
#if defined(__linux__)
        "  call  compte_autour\n"
#else
        "  call  _compte_autour\n"
#endif
        "  movl  %eax, -24(%rbp)\n"
        "  movl  -24(%rbp), %eax\n"
        "  cmpl  -20(%rbp), %eax\n"
#if defined(__linux__)
        "  jle .L505\n"
#else
        "  jle L505\n"
#endif
        "  movl  -24(%rbp), %eax\n"
        "  movl  %eax, -20(%rbp)\n"
        "  movl  -4(%rbp), %eax\n"
        "  movl  %eax, -12(%rbp)\n"
        "  movl  -8(%rbp), %eax\n"
        "  movl  %eax, -16(%rbp)\n"
#if defined(__linux__)
        ".L505:\n"
#else
        "L505:\n"
#endif
        "  addl  $1, -8(%rbp)\n"
#if defined(__linux__)
        ".L503:\n"
        "  cmpl  $19, -8(%rbp)\n"
        "  jle .L506\n"
        "  addl  $1, -4(%rbp)\n"
        ".L502:\n"
#else
        "L503:\n"
        "  cmpl  $19, -8(%rbp)\n"
        "  jle L506\n"
        "  addl  $1, -4(%rbp)\n"
        "L502:\n"
#endif
        "  cmpl  $19, -4(%rbp)\n"
#if defined(__linux__)
        "  jle .L507\n"
#else
        "  jle L507\n"
#endif
        "  movq  -40(%rbp), %rax\n"
        "  movl  -12(%rbp), %edx\n"
        "  movl  %edx, (%rax)\n"
        "  movq  -40(%rbp), %rax\n"
        "  leaq  4(%rax), %rdx\n"
        "  movl  -16(%rbp), %eax\n"
        "  movl  %eax, (%rdx)\n"
        "  leave\n"
#if defined(__linux__)
        ".cfi_def_cfa 7, 8\n"
        "ret\n"
        ".cfi_endproc\n"
#else
        "ret\n"
#endif
    );
    /**
      Non ! L'erreur que vous cherchez ne se situe pas DU TOUT ici !
      ...

      Non mais vraiment, l'erreur de compilation est dûe à une des premières fonctions du programme.
      **/
#else
    asm(
#if defined(__linux__)
        "  .globl  ia_mystere\n"
        "ia_mystere:\n"
        ".cfi_startproc\n"
#else
        "  .globl  _ia_mystere\n"
        "_ia_mystere:\n"
#endif
        ".LFB0:\n"
#if defined(__linux__)
        "  .cfi_startproc\n"
#endif
        "  pushl %ebp\n"
#if defined(__linux__)
        "  .cfi_def_cfa_offset 8\n"
        "  .cfi_offset 5, -8\n"
#endif
        "  movl  %esp, %ebp\n"
#if defined(__linux__)
        "  .cfi_def_cfa_register 5\n"
#endif
        "  subl  $40, %esp\n"
        "  movl  $" STR(SIZE/2) ", -20(%ebp)\n"
        "  movl  $" STR(SIZE/2) ", -24(%ebp)\n"
        "  subl  $12, %esp\n"
        "  pushl 20(%ebp)\n"
        "  pushl 16(%ebp)\n"
        "  pushl -24(%ebp)\n"
        "  pushl -20(%ebp)\n"
        "  pushl 12(%ebp)\n"
#if defined(__linux__)
        "  call  compte_autour\n"
#else
        "  call  _compte_autour\n"
#endif
        "  addl  $32, %esp\n"
        "  movl  %eax, -28(%ebp)\n"
        "  movl  $0, -12(%ebp)\n"
#if defined(__linux__)
        "  jmp .L502\n"
        ".L507:\n"
        "  movl  $0, -16(%ebp)\n"
        "  jmp .L503\n"
        ".L506:\n"
        "  call  rand\n"
#else
        "  jmp L502\n"
        "L507:\n"
        "  movl  $0, -16(%ebp)\n"
        "  jmp L503\n"
        "L506:\n"
        "  call  _rand\n"
#endif
        "  cltd\n"
        "  movl $" STR(SIZE) ", %ebx\n"
        "  idivl %ebx\n"
        "  movl  %edx, %eax\n"
        "  testl %eax, %eax\n"
#if defined(__linux__)
        "  jne .L504\n"
#else
        "  jne L504\n"
#endif
        "  subl  $12, %esp\n"
        "  pushl 20(%ebp)\n"
        "  pushl  $" STR(RADAR) "\n"
        "  pushl -16(%ebp)\n"
        "  pushl -12(%ebp)\n"
        "  pushl 12(%ebp)\n"
#if defined(__linux__)
        "  call  radar\n"
#else
        "  call  _radar\n"
#endif
        "  addl  $32, %esp\n"
#if defined(__linux__)
        ".L504:\n"
#else
        "L504:\n"
#endif
        "  subl  $12, %esp\n"
        "  pushl 20(%ebp)\n"
        "  pushl 16(%ebp)\n"
        "  pushl -16(%ebp)\n"
        "  pushl -12(%ebp)\n"
        "  pushl 12(%ebp)\n"
#if defined(__linux__)
        "  call  compte_autour\n"
#else
        "  call  _compte_autour\n"
#endif
        "  addl  $32, %esp\n"
        "  movl  %eax, -32(%ebp)\n"
        "  movl  -32(%ebp), %eax\n"
        "  cmpl  -28(%ebp), %eax\n"
#if defined(__linux__)
        "  jne .L505\n"
#else
        "  jne L505\n"
#endif
        "  movl  -32(%ebp), %eax\n"
        "  movl  %eax, -28(%ebp)\n"
        "  movl  -12(%ebp), %eax\n"
        "  movl  %eax, -20(%ebp)\n"
        "  movl  -16(%ebp), %eax\n"
        "  movl  %eax, -24(%ebp)\n"
#if defined(__linux__)
        ".L505\n"
        "  addl  $1, -16(%ebp)\n"
        ".L503\n"
        "  cmpl  $19, -16(%ebp)\n"
        "  jle .L506\n"
        "  addl  $1, -12(%ebp)\n"
        ".L502:\n"
        "  cmpl  $19, -12(%ebp)\n"
        "  jle .L507\n"
#else
        "L505\n"
        "  addl  $1, -16(%ebp)\n"
        "L503\n"
        "  cmpl  $19, -16(%ebp)\n"
        "  jle L506\n"
        "  addl  $1, -12(%ebp)\n"
        "L502:\n"
        "  cmpl  $19, -12(%ebp)\n"
        "  jle L507\n"
#endif
        "  movl  8(%ebp), %eax\n"
        "  movl  -20(%ebp), %edx\n"
        "  movl  %edx, (%eax)\n"
        "  movl  8(%ebp), %eax\n"
        "  leal  4(%eax), %edx\n"
        "  movl  -24(%ebp), %eax\n"
        "  movl  %eax, (%edx)\n"
        "  leave\n"
#if defined(__linux__)
        "  .cfi_restore 5\n"
        "  .cfi_def_cfa 4, 4\n"
        "  ret\n"
        "  .cfi_endproc\n"
#else
        "  ret\n"
#endif
    );
#endif
    /**
      Non ! L'erreur que vous cherchez ne se situe pas DU TOUT ici !
      ...

      Non mais vraiment, l'erreur de compilation est dûe à une des premières fonctions du programme.
      **/
