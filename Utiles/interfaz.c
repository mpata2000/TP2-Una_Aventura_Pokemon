/*
 * Aca es donde los prints vienen a morir
 * Tener cuidado con los copy pastes
*/
#include "interfaz.h"
#include "../Estructura/gimnasio.h"
#include "../Estructura/personaje.h"
#include "../TDAs/heap.h"
#include "../Utiles/ANSI-color-codes.h"


void pantalla_de_carga(const char* mensaje){
    system("clear");
    int i;
    int pokemon_num = rand()%POKEMON_ASCII;
	char carga[110];

	
	for(i=0; i<101; i++){
		carga[i]= '.';
	}
	for(i=0; i<101; i++){
        if((i%20) == 0){
            pokemon_num = rand()%POKEMON_ASCII;
        }
        printf(GRN" » %s "reset"\n",mensaje);
        printf(GRN" » Mientras espera mire estos Pokemon"reset"\n\n\n\n"reset);		
        mostrar_pokemon_ascii(pokemon_num);
        printf("\n");
        printf("        |");

		for(int j=0; j<100; j++){
			if(carga[j] == '#'){
				printf(GRN"%c"reset,carga[j]);
				
			}else{
				printf("%c",carga[j]);
			}	
		}	
		
		printf("|  %i%%\n",i);
		detener_tiempo(0.1f);
		carga[i]= '#';
		system("clear");
	}	

}

void mostrar_carga_juego(){
    system("clear");
    int i;
	char carga[110];

	
	for(i=0; i<101; i++){
		carga[i]= '.';
	}
	for(i=0; i<101; i++){
		printf( BLU "                                                          d8888                            888                              "reset"\n");
        printf( BLU "                                                         d88888                            888                              "reset"\n");
        printf( BLU "                                                        d88P888                            888                              "reset"\n");
        printf( BLU "                                                       d88P 888 888  888  .d88b.  88888b.  888888 888  888 888d888 8888b.   "reset"\n");
        printf( BLU "                                                      d88P  888 888  888 d8P  Y8b 888 \"88b 888    888  888 888P\"      \"88b  "reset"\n");
        printf( BLU "                                                     d88P   888 Y88  88P 88888888 888  888 888    888  888 888    .d888888  "reset"\n");
        printf( BLU "                                                    d8888888888  Y8bd8P  Y8b.     888  888 Y88b.  Y88b 888 888    888  888  "reset"\n");
        printf( BLU "                                                   d88P     888   Y88P    \"Y8888  888  888  \"Y888  \"Y88888 888    \"Y888888  "reset"\n");
        printf( BLU "                                                                                                                            "reset"\n");
        printf( BLU "                                                                                  `  .znzi`                                                               "reset"\n");
        printf( BLU "                                                                                 ` `.#nzzz:`                                                              "reset"\n");
        printf( BLU "                                                                                   .#nzz#z#.                                                              "reset"\n");
        printf( BLU "                                                                      `          ``+zzz##zz*`      ``                 `                                   "reset"\n");
        printf( BLU "                                                                 `     `     `   `inzz+" BYEL "i+" BLU "#zz:                    `    `                                   "reset"\n");
        printf( BLU "                                     ```                          `  ` `       ``;zzz#" BYEL "ii*" BLU "+#nz.`          ``` `  ``                                        "reset"\n");
        printf( BLU "                                                            ```  ````.``    `  `:zzzz" BYEL "*ii*" BLU "#znz:` ``     ``    `  ```                                       "reset"\n");
        printf( BLU "                                                       `````````,;+;+#*`  ``  `,#zzz" BYEL "iii" BLU "+zzz+,`````  ```````````````                                       "reset"\n");
        printf( BLU "                     `      ```..,,,.```  ``         ````````,*#znznnzn*. ````.#zzz" BYEL "ii" BLU "#nnz+,`   ```````.;#nnnnnnz#.                `                       "reset"\n");
        printf( BLU "                          `.:i*##zz#z#+*;,`         ` ```.:i+#zzzzzz#zzz*,```.#zzzz" BYEL "+" BLU "znz+:. ` ``;*++++++#zzzznnzz#:    ` `````      ` ``                   "reset"\n");
        printf( BLU "                       ``:*+#zzzzzzzzzzzz#i.        ``.,*#zzznzz#zz#zz#nz#.``+Mxzzzzzzz*i:```.+xzznnnnzzzzz+##+zz;     ` .*#*;.```                        "reset"\n");
        printf( BLU "                     `.i#nznnnzz######zznzzz:`      `iznzznnz#" BYEL "**" BLU "#nzzzz" BYEL "+" BLU "#nn#,`,xxnzzzzzznnn#i`,nnzzz##z##znz" BYEL "***" BLU "+zni      ,xWnznzz+i:.``                    "reset"\n");
        printf( BLU "                    .;#zznzz#" BYEL "++++**+**++" BLU "#zzn#:      .WMzzz++" BYEL "**i*" BLU "#nzzn" BYEL "**+" BLU "#zz#:`+nzzzzz###zzzz+ixnzn+" BYEL "**+*" BLU "+zn#" BYEL "ii*" BLU "+zn+      :xMzzzznnnzz+i:```                "reset"\n");
        printf( BLU "              ` ` `:+znnz#" BYEL "+****iiiiiii*++" BLU "##nz#,```  .Wxzn*;" BYEL "iiii+" BLU "+zzn#" BYEL "ii++" BLU "#znz+zznz###+++##zz#zxnzn" BYEL "*iii*" BLU "+zn+" BYEL "i**" BLU "+#n#``    ,xxzz###zznnnzzii*;,``` ``        "reset"\n");
        printf( BLU "                 ,+nznz" BYEL "+*iiiiiiiiiiiiiiii*+" BLU "#nn#`` ` `Mxzn#z#" BYEL "iii*" BLU "+nn#" BYEL "iiii*+" BLU "+nnznz+" BYEL "*iii;ii*" BLU "++#nnzzzz" BYEL "iiii**" BLU "#n" BYEL "+iii*" BLU "#nn.`   `.xxzz" BYEL "**++++" BLU "#zzznxzzzz+;,``        "reset"\n");
        printf( BLU "              ` ;znzz" BYEL "+*iiiiiiiiiiiiiii*iii*+" BLU "zzz: `` `Mnzzzz#" BYEL "iiii" BLU "+xz" BYEL "iiiiii**" BLU "#znz" BYEL "*iiiiiiiiii" BLU "++#nzzz#" BYEL "iiii**" BLU "#n" BYEL "*iii*" BLU "#nn, ````.nxzzz" BYEL "+*i***" BLU "+zzzzzzznznzz+;`      "reset"\n");
        printf( BLU "               :MMzz#" BYEL "iii**iiiiiiiiiiiii*iii++" BLU "zz*`` ` Mnzzzz+" BYEL ";ii*" BLU "+x" BYEL "*;iiii*i+" BLU "nzn" BYEL "*iii*" BLU "zzz#" BYEL "*iii*" BLU "znzzz#" BYEL "iiiii*" BLU "+n" BYEL "iiii*" BLU "+zz: ````.zxzzzz" BYEL "ii*ii+" BLU "zzzzn#+#zznnnz.      "reset"\n");
        printf( BLU "              `:WWnzz" BYEL "+;iiiii*iiiiiiiiiiiiiii+" BLU "#n#.````xnzxnnz" BYEL "iiii" BLU "##" BYEL "ii**iii+" BLU "nzn+" BYEL "iii" BLU "#nz#zxn" BYEL "iii" BLU "#nnnzn+" BYEL "iiiii*" BLU "+n" BYEL "iiiii" BLU "+zz;``.:;*znnzz#" BYEL "ii*i**" BLU "znznn" BYEL "+*++++" BLU "zz*`      "reset"\n");
        printf( BLU "               `zMxzzn" BYEL "ii*i*iiiiiiii" BLU "#zzz" BYEL "+ii*i+" BLU "#nz.`   i;#Wxnz" BYEL "i*i*" BLU "+" BYEL "*ii*ii;+" BLU "nnzn" BYEL "iii" BLU "+x#:;zn+" BYEL "ii" BLU "#nznxzn" BYEL "*iiiii*" BLU "+#" BYEL "iiiii" BLU "#zn*,izznnznnnz#" BYEL "iiiii*" BLU "#zznz" BYEL "iii*i" BLU "+nn;       "reset"\n");
        printf( BLU "                :xMzzn#" BYEL "iii*iiiiiii+" BLU "nnnnz#" BYEL "iii*" BLU "#n#,`.:;ii#xnzn" BYEL "iii**iii*i;*" BLU "zzzzz" BYEL "ii*" BLU "#n;.#n+" BYEL "ii" BLU "#nzzxxnz" BYEL "*iiiii*" BLU "+" BYEL "*ii*ii" BLU "+zz##nnnz#zznzn#" BYEL "iiiii*" BLU "#zzz#" BYEL ";iiii" BLU "#nz,       "reset"\n");
        printf( BLU "             `` `*Mxnzn" BYEL "*;iiiiiiiii+" BLU "zz++zn" BYEL "+ii*" BLU "#n#:*zznxnnnnzz" BYEL "*ii*iiiii;*" BLU "zn#zn+" BYEL "i*i" BLU "#z:+x+" BYEL ":;" BLU "#nnnznnnz" BYEL "*iiiii**iii*i*" BLU "+#zznn" BYEL "+*+++++" BLU "znn+" BYEL "iii**" BLU "#zzn" BYEL "+;i*i*" BLU "zn*`       "reset"\n");
        printf( BLU "             `   .zMnnn#" BYEL "*zn*iiiiii*" BLU "zn*:#n#" BYEL "ii*" BLU "zzzzxzz#z##zznz" BYEL "*;*iiii*i*" BLU "zz+:#n" BYEL "+i*i" BLU "#n#xz" BYEL "i;" BLU "+nnz#znznz" BYEL "iiiiiiiiiii*ii*" BLU "#zn#" BYEL "i*" BLU "#z+" BYEL "i*++" BLU "#nn" BYEL "*iiii" BLU "+#zn" BYEL "*i**i" BLU "+zn;`       "reset"\n");
        printf( BLU "                  ;Mxnnnzzn" BYEL "+iiiiii*" BLU "#n#,#n#" BYEL "ii*" BLU "zznnn" BYEL "*ii++++" BLU "#znz" BYEL "iiiiii*+" BLU "nnz*:+n#" BYEL "ii**" BLU "nn#" BYEL "ii" BLU "+nnz" BYEL "*" BLU "+zxnn#" BYEL "iiiiiiiiiiiiii+" BLU "zn" BYEL "+i*" BLU "nz" BYEL "*iii**" BLU "#nn" BYEL "+iiii+" BLU "#nz" BYEL "*ii*i" BLU "#nz.`       "reset"\n");
        printf( BLU "                  `zxnznnznz" BYEL "i*iiiii*" BLU "zn;zx" BYEL "*ii" BLU "#nzn#" BYEL "ii+" BLU "##" BYEL "*i*++" BLU "nxz" BYEL ";iiii*" BLU "#nznnnzzz" BYEL "i*i*" BLU "##" BYEL "ii" BLU "+nz" BYEL "+ii*" BLU "+#nnn#" BYEL "iiiiiiii*iiii" BLU "nn#" BYEL "ii" BLU "zn#" BYEL ";ii*" BLU "#" BYEL "*+" BLU "znz" BYEL "*iii" BLU "++n#" BYEL "i*ii*" BLU "zn+```      "reset"\n");
        printf( BLU "                   ,nxznzzzn" BYEL "*iiiiiii" BLU "#zznn" BYEL ";;*" BLU "nnn" BYEL "+ii" BLU "zx#" BYEL "iii**++" BLU "nn" BYEL ";iiiii+++" BLU "#nnnzn" BYEL "*iiiiii*++iiii***" BLU "#nnn" BYEL "*ii" BLU "++" BYEL "iiiiiii" BLU "#xz" BYEL "*i+" BLU "zzz+" BYEL "ii" BLU "+" BLU "n" BYEL "**+" BLU "zn" BYEL "*iii*" BLU "+n+" BYEL "i*ii" BLU "+nn; `       "reset"\n");
        printf( BLU "                   `+xxnxnzn#" BYEL "iii*iii" BLU "#nnn" BYEL "*;i" BLU "znn#" BYEL ";i*" BLU "nz+" BYEL ";ii" BLU "##" BYEL "i+" BLU "#n" BYEL "+;iiii***+" BLU "##zznz" BYEL "iiiiii*iiiii*ii" BLU "+znz" BYEL "*iii" BLU "#z" BYEL "iiii+i*" BLU "zn#" BYEL "i*+" BLU "#zznzznn" BYEL "ii+" BLU "nn" BYEL "i*ii*" BLU "#n" BYEL "*iiii" BLU "#nz, `       "reset"\n");
        printf( BLU "                    .#*ixxznn" BYEL "i*iiiii+" BLU "xn" BYEL "*ii" BLU "#xxn" BYEL "*i*+" BLU "nzn" BYEL "i;i" BLU "n#" BYEL "i+" BLU "#n#" BYEL "i*iiiiii**++" BLU "#nx#" BYEL "iiiiii*iiiii*" BLU "#nnz" BYEL "*;ii*" BLU "#n" BYEL "*ii*zi" BLU "+nn+" BYEL "i*+" BLU "#nznnnx+" BYEL "ii" BLU "+nn" BYEL "i*" BLU "+" BYEL "i*+" BLU "z" BYEL "iiii*" BLU "zn+` `       "reset"\n");
        printf( BLU "                     ` .zMxzn#" BYEL "iiiiii++i;i" BLU "znnn#" BYEL "ii*+" BLU "nnnnnzn" BYEL "+i*" BLU "#nz" BYEL "ii+" BLU "#" BYEL "iii*iii*+" BLU "znnz" BYEL "*iiiiiiii*" BLU "#nnnnz" BYEL "iiii*" BLU "zn#" BYEL "ii+xi" BLU "+nz" BYEL "*ii*+" BLU "#znnn#" BYEL "ii*" BLU "#xz" BYEL "i" BLU "+#" BYEL "i*+*iiii+" BLU "nn;``        "reset"\n");
        printf( BLU "                       `iMxzzn" BYEL "**iiii*i;i" BLU "#xzzz" BYEL "*ii*+" BLU "nxznnnz" BYEL "ii*" BLU "#xz" BYEL "i*+" BLU "nz+" BYEL "i;iii*++" BLU "#nnnz++" BYEL "*i" BLU "+#znnnzzn#" BYEL "iiii+" BLU "nnz" BYEL "*i#x*" BLU "+nn" BYEL "iiii+" BLU "#+##+" BYEL "iiii" BLU "zx#" BYEL "i" BLU "#" BYEL "+i***iiii" BLU "#nz,          "reset"\n");
        printf( BLU "                        .xMxzn#" BYEL "iiiiiii*" BLU "znnnzn" BYEL "*i*i+" BLU "#nnnnn" BYEL "*i**" BLU "#n#" BYEL ";i+" BLU "nnnn#" BYEL "i;ii*+" BLU "#znnnnnzznnnzzznzn" BYEL "+i**i+" BLU "nnnz" BYEL "*zn" BLU "++nn+" BYEL ";ii*****iiii*" BLU "xn" BYEL "*i" BLU "#+" BYEL "i*iiiii" BLU "*zn+`          "reset"\n");
        printf( BLU "                         +MMnzn" BYEL "iiiii**" BLU "zxnznnn" BYEL "*iiii+" BLU "#++" BYEL "+iiii+" BLU "nx" BYEL "+ii+" BLU "znnnnn#" BYEL "*;ii*++" BLU "zznnznnnnzzMxzz" BYEL "*iiii+" BLU "nzznznn" BYEL "+*" BLU "zx#" BYEL "iiiiiii*iiii" BLU "zxz" BYEL "i*" BLU "z#" BYEL "i*ii*i*+" BLU "zn;`          "reset"\n");
        printf( BLU "                         .xMnzn" BYEL "+iiii*+" BLU "#nznMnz" BYEL "*ii*ii**iii*ii" BLU "zxx" BYEL "ii*" BLU "#nnnzznnn#" BYEL "ii***+++" BLU "znnnn+;iWxxn+" BYEL "**i*" BLU "#nzznnzn#" BYEL "*" BLU "#nn+" BYEL "iiii*iiiii" BLU "#nn" BYEL "*i*" BLU "z#" BYEL "iiiiii*" BLU "#nn.`          "reset"\n");
        printf( BLU "                        ``#Mxnnn" BYEL ";i*ii+" BLU "#nznxzn" BYEL "+iiiiiiii*ii;i" BLU "nn#" BYEL ";i*" BLU "#nnxxxzzzxn#" BYEL "*iiii+" BLU "nnz:.` *Mxnnnxxnnznznnzznz" BYEL "i*" BLU "znx" BYEL "*;iiiii;i" BLU "#xn" BYEL "+ii" BLU "+n#" BYEL "iiiiii*" BLU "zn#`           "reset"\n");
        printf( BLU "                          :MMnnx" BYEL "*iiii*" BLU "#zznxnnz" BYEL "*iii*iiiiiii" BLU "zxn" BYEL "*;**" BLU "#nn*nMMxnnnxx#" BYEL "*i;*" BLU "zn#````zMxnzznzznxznnnnznn" BYEL "*++" BLU "nxx+" BYEL "*iii*" BLU "+nxn" BYEL "+;*i" BLU "+n#" BYEL "iii*i*" BLU "+xni            "reset"\n");
        printf( BLU "                         ``zMxnnz" BYEL "iiiii+" BLU "znnxxnn#" BYEL ";iii*iii;;" BLU "#xnn" BYEL "*ii*" BLU "#nn..inMxnzznxn#" BYEL "ii" BLU "zn#````i#nxxxxnnnnzxxnnnnn" BYEL "**++" BLU "nxnnzznnnznn" BYEL "*i*i" BLU "#n#" BYEL "ii*ii*" BLU "#xz,            "reset"\n");
        printf( BLU "                        `` ;WWxnn" BYEL "*iiii+" BLU "#xnxMnnn#" BYEL "i;iii;;*" BLU "znnnn" BYEL "+iii" BLU "+nn.` .inMxxnnnxn#znz``` ```.:i+#xM#;MMxnnzn" BYEL "*;i*" BLU "+#znnznnzzzx" BYEL "**ii" BLU "#n#" BYEL "ii*ii*" BLU "zn+`            "reset"\n");
        printf( BLU "                           .xMxnn#" BYEL "ii*i*+" BLU "xnzMxnnnn#" BYEL "***" BLU "#nxnnnzn" BYEL "+i*+" BLU "#zn. ````inMMxnznxnn#` ` ` ` ````````+n#Mnznnnz##+znn#++Mnnzii;;" BLU "zxz" BYEL "ii*ii" BLU "+nn; `           "reset"\n");
        printf( BLU "                            +WMznn" BYEL "ii*i*+" BLU "nn##Mxxnnnnnnxnnznnznnnnnnnn.``   `.;nMMxnznnz` `           ``..;Wxnnnnxxnznnz,.iWxnnzz#+zxz" BYEL "iiiii" BLU "#nz,``           "reset"\n");
        printf( BLU "                            .MWxnn#" BYEL "ii*i+" BLU "znz,#MMxnnnnnznz:nxnnnnnnznn.``    ` `inMMxnnz``                :MWMxxnzzzznn#.`+WMnnnnxxxnz" BYEL "iiiii" BLU "zn+.`            "reset"\n");
        printf( BLU "                             +WMznn" BYEL "ii*i*" BLU "#nni`;nMWWWMMz;.`zxxxxnzzz;` `         `;zMWM#`  `             ``;i+zxMMWMxxn#.`#MMxnnnnnnnz" BYEL "iiii" BLU "+nn; `            "reset"\n");
        printf( BLU "                             :MMxnx" BYEL "+iiii+" BLU "nx*.``;*+*i:.` `+z*i;:..```   `    ``   .;#i.`  `            ```  ``.,;*#xM#,` ,;*+zxxMxnnz" BYEL "iii*" BLU "#nn. `            "reset"\n");
        printf( BLU "                             `#WMnxn" BYEL "iiii+" BLU "nnz```  `       ```      `                `                             ````      ```.+Mnnn#" BYEL "*;i" BLU "zn#``   `         "reset"\n");
        printf( BLU "                              :WWxnn" BYEL "++" BLU "znxnnn.``                                                                            `   iWxnnxxxznni  ` ``         "reset"\n");
        printf( BLU "                              .nWMnnznnxnnn*. `                                                                                iWMxnnnxnnz,`         "reset"\n");
        printf( BLU "                              `*WMxnnnnnMz:`` `                                                                             `  .*xWWMxnzn+`        "reset"\n");
        printf( BLU "                               .xWMnxz#i`  `                                                                                    ``.;zxWWz,`       "reset"\n");
        printf( BLU "                                *Mx#i,`                                                                                         ``  `.;;.``        "reset"\n");
        printf("\n");
        printf("                                 |");

		for(int j=0; j<100; j++){
			if(carga[j] == '#'){
				printf(GRN"%c"reset,carga[j]);
				
			}else{
				printf("%c",carga[j]);
			}	
		}	
		
		printf("|  %i%%\n",i);
		detener_tiempo(0.1f);
		carga[i]= '#';
		system("clear");
	}	

     
	printf(reset);
}




/***
 *    ,-,-,-.                 ,-_/                 
 *    `,| | |   ,-. ,-. . .   '  | ,-. . ,-. . ,-. 
 *      | ; | . |-' | | | |   .^ | | | | |   | | | 
 *      '   `-' `-' ' ' `-^   `--' ' ' ' `-' ' `-' 
 *                                                                                       
 */


void menu_inicio_header(){
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#                         ,-,-,-.                 ,-_/                                         #\n");
    printf("#                         `,| | |   ,-. ,-. . .   '  | ,-. . ,-. . ,-.                         #\n");
    printf("#                           | ; | . |-' | | | |   .^ | | | | |   | | |                         #\n");
    printf("#                           '   `-' `-' ' ' `-^   `--' ' ' ' `-' ' `-'                         #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#                            .\"-,.__                                                           #\n");
    printf("#                            `.     `.  ,                                                      #\n");
    printf("#                         .--'  .._,'\"-' `.                                                    #\n");
    printf("#                        .    .'         `'                                                    #\n");
    printf("#                        `.   /          ,'                                                    #\n");
    printf("#                          `  '--.   ,-\"'                                                      #\n");
    printf("#                           `\"`   |  \\                                                         #\n");
    printf("#                              -. \\, |                                                         #\n");
    printf("#                               `--Y.'      ___.                                               #\n");
    printf("#                                    \\     L._, \\                                              #\n");
    printf("#                          _.,        `.   <  <\\                _                              #\n");
    printf("#                        ,' '           `, `.   | \\            ( `                             #\n");
    printf("#                     ../, `.            `  |    .\\`.           \\ \\_                           #\n");
    printf("#                    ,' ,..  .           _.,'    ||\\l            )  '\".                        #\n");
    printf("#                   , ,'   \\           ,'.-.`-._,'  |           .  _._`.                       #\n");
    printf("#                 ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\                      #\n");
    printf("#               .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`.                    #\n");
    printf("#               |  '          ..         `-...-\"  |  `-'      / /        . `.                  #\n");
    printf("#               | /           |L__           |    |          / /          `. `.                #\n");
    printf("#              , /            .   .          |    |         / /             ` `                #\n");
    printf("#             / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \\               #\n");
    printf("#            / .           \\\"`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`.              #\n");
    printf("#           .  '         .-f    ,'   `    '.       \\__.---'     _   .'   '     \\ \\             #\n");
    printf("#           ' /          `.'    l     .' /          \\..      ,_|/   `.  ,'`     L`             #\n");
    printf("#           |'      _.-\"\"` `.    \\ _,'  `            \\ `.___`.'\"`-.  , |   |    | \\            #\n");
    printf("#           ||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|            #\n");
    printf("#           ||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||            #\n");
    printf("#           || '              V      / /           `   | `   ,'   ,' '.    !  `. ||            #\n");
    printf("#           ||/            _,-------7 '              . |  `-'    l         /    `||            #\n");
    printf("#           . |          ,' .-   ,' ||               | .-.        `.      .'     ||            #\n");
    printf("#            `'        ,'    `\".'    |               |    `.        '. -.'       `'            #\n");
    printf("#                     /      ,'      |               |,'    \\-.._,.'/'                         #\n");
    printf("#                     .     /        .               .       \\    .''                          #\n");
    printf("#                   .`.    |         `.             /         :_,'.'                           #\n");
    printf("#                     \\ `...\\   _     ,'-.        .'         /_.-'                             #\n");
    printf("#                      `-.__ `,  `'   .  _.>----''.  _  __  /                                  #\n");
    printf("#                           .'        /\"'          |  \"'   '_                                  #\n");
    printf("#                          /_|.-'\\ ,\".             '.'`__'-( \\                                 #\n");
    printf("#                            / ,\"'\"\\,'               `/  `-.|\" mh                              #\n");
}

/*
 * E: Ingresa el archivo del entrenador principal.
 * A: Agrega un gimnasio al árbol de gimnasios.
 * I: Comienza la partida.
 * S: Simula la partida.
*/
void mostrar_menu_inicio(juego_t* juego){
    system("clear");

    menu_inicio_header();
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#   Presione:                                                                                  #\n");
    printf("#                                                                                              #\n");
    printf("#   ");
    if(juego->personaje){
        printf("- 'E' para Ingresar Entrenador Principal"); // Cambio de color
    }else{
        printf("- 'E' para Ingresar Entrenador Principal");
    }
    printf("              - 'A' para Agregar un Gimnasio       #\n");

    // TODO: Cambiar color cuando la partida sea valida
    printf("#   - 'I' Comenzar la partida                             - 'S' Simular la Partida             #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");


}

void info_cargar_personaje(){
    system("clear");
    menu_inicio_header();

    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#   Esta Ingresando el Entrenador Principal recuerde:                                          #\n");
    printf("#      - El archivo tiene que estar en Archivos/Personaje                                      #\n");
    printf("#      - El archivo tiene que tener el formato que se encuentra en el README                   #\n");
    printf("#      - Solo puede cargar un Entrenador Principal por partida                                 #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
}



void info_cargar_gimnasio(){
    system("clear");
    menu_inicio_header();

    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#   Esta Ingresando uno o varios Gimnasios:                                                    #\n");
    printf("#      - El archivo tiene que estar en Archivos/Gimnasios                                      #\n");
    printf("#      - El archivo tiene que tener el formato que se encuentra en el README                   #\n");
    printf("#      - Puede haber uno o mas gimnasios en el archivo                                         #\n");
    printf("#      - Todos los gimnasios tienen que tener un lider con Pokemon                             #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
}


/***    
 * Menu Gimnasio:
 * E: Muestra al entrenador principal junto a sus Pokémon.
 * G: Muestra la información del gimnasio actual.
 * C: Permite cambiar los Pokémon de batalla.
 * B: Realiza la próxima batalla planificada.
*/
void mostrar_menu_gimnasio(juego_t* juego){
    system("clear");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#                   ,-,-,-.                 ,---.                                              #\n");
    printf("#                   `,| | |   ,-. ,-. . .   |  -'  . ,-,-. ,-. ,-. ,-. . ,-.                   #\n");
    printf("#                     | ; | . |-' | | | |   |  ,-' | | | | | | ,-| `-. | | |                   #\n");
    printf("#                     '   `-' `-' ' ' `-^   `---|  ' ' ' ' ' ' `-^ `-' ' `-'                   #\n");
    printf("#                                            ,-.|                                              #\n");
    printf("#                                            `-+'                                              #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#                           )\\         O_._._._A_._._._O         /(                            #\n");
    printf("#                            \\`--.___,'=================`.___,--'/                             #\n");
    printf("#                             \\`--._.__                 __._,--'/                              #\n");
    printf("#                               \\  ,. l`~~~~~~~~~~~~~~~'l ,.  /                                #\n");
    printf("#                   __            \\||(_)!_!_!_.-._!_!_!(_)||/            __                    #\n");
    printf("#                   \\\\`-.__        ||_|____!!_|;|_!!____|_||        __,-'//                    #\n");
    printf("#                    \\\\    `==---='-----------'='-----------`=---=='    //                     #\n");
    printf("#                    | `--.                                         ,--' |                     #\n");
    printf("#                     \\  ,.`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~',.  /                      #\n");
    printf("#                       \\||  ____,-------._,-------._,-------.____  ||/                        #\n");
    printf("#                        ||\\|___!`=======\"!`=======\"!`=======\"!___|/||                         #\n");
    printf("#                        || |---||--------||-| | |-!!--------||---| ||                         #\n");
    printf("#              __O_____O_ll_lO_____O_____O|| |'|'| ||O_____O_____Ol_ll_O_____O__               #\n");
    printf("#              o H o o H o o H o o H o o |-----------| o o H o o H o o H o o H o               #\n");
    printf("#             ___H_____H_____H_____H____O =========== O____H_____H_____H_____H___              #\n");
    printf("#                                      /|=============|\\                                       #\n");
    printf("#            ()______()______()______() '==== +-+ ====' ()______()______()______()             #\n");
    printf("#            ||{_}{_}||{_}{_}||{_}{_}/| ===== |_| ===== |\\{_}{_}||{_}{_}||{_}{_}||             #\n");
    printf("#            ||      ||      ||     / |==== s(   )s ====| \\     ||      ||      ||             #\n");
    printf("#            ======================()  =================  ()======================             #\n");
    printf("#            ----------------------/| ------------------- |\\----------------------             #\n");
    printf("#                                 / |---------------------| \\                                  #\n");
    printf("#            -'--'--'           ()  '---------------------'  ()                                #\n");
    printf("#                               /| ------------------------- |\\    --'--'--'                   #\n");
    printf("#                   --'--'     / |---------------------------| \\    '--'                       #\n");
    printf("#                            ()  |___________________________|  ()           '--'-             #\n");
    printf("#              --'-          /| _______________________________  |\\                            #\n");
    printf("#             --' gpyy      / |__________________________________| \\                           #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#   Ingrese:                                                                                   #\n");
    printf("#                                                                                              #\n");
    printf("#   - 'E' Mostrar Entrenador Principal                    - 'G' Mostrar Gimnasio actual        #\n");
    printf("#   - 'C' Cambiar Pokemon                                 - 'B' Proxima batalla                #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
}

/*
 * Aquí se mostrará la información de la batalla, Pokémon vs Pokémon.
 * Deberá ser informativa: mostrar cuál es el Pokémon del rival y cuál es el tuyo, sus características y el resultado del
 * combate.
 * 
 * N: Próximo combate.
*/
void mostrar_batalla(juego_t* juego,pokemon_t* pkm_jugador,pokemon_t* pkm_entrenador,int ganador){
    pokemon_t* pkm_ganador = NULL;
    char ganador_txt[300];

    entrenador_t* entrenador = gimnasio_entrenador_a_pelear(juego->gimnasio_actual);
    if(ganador == GANO_PRIMERO){
        pkm_ganador = pkm_jugador;
        strcpy(ganador_txt,pokemon_nombre(pkm_ganador));
        strcat(ganador_txt," de ");
        strcat(ganador_txt,juego->personaje->nombre);
    }else{
        pkm_ganador = pkm_jugador;
        strcpy(ganador_txt,pokemon_nombre(pkm_ganador));
        strcat(ganador_txt," de ");
        strcat(ganador_txt,entrenador->nombre);
    }

    system("clear");
    printf("   .──────────────────────────────────────────────────────────────────────.    \n");
    printf("  │    OFF *  * ON                                                         │⠀  \n");
    printf("  │   ┌────────────────────────────────────────────────────────────────.   │⠀  \n");
    printf("  │   │                                                                │   │   \n");
    printf("  │   │       ┌──────────────────────────────────────────────────┐     │   │   \n");
    printf("  │   │       │ »"BGRN" %-20s"reset"                     │     │   │   \n",juego->gimnasio_actual->nombre); //NOMBRE DEL GIMNASIO
    printf("  │   │  "BRED"O"reset" »» │ » Batalla Pokemon                                │     │   │   \n");
    printf("  │   │ POWER │                                                  │     │   │   \n");
    printf("  │   │       │ » "BMAG"%-20s"reset"                           │     │   │   \n",juego->personaje->nombre); //PERSONAJE
    printf("  │   │       │   » "BWHT"%-17s"reset"                            │     │   │   \n",pkm_jugador->nombre);
    printf("  │   │       │     ·"BRED"Ataque:"reset"    %-5i                            │     │   │   \n",pokemon_ataque(pkm_jugador));
    printf("  │   │       │     ·"BBLU"Defensa:"reset"   %-5i                            │     │   │   \n",pokemon_defensa(pkm_jugador));
    printf("  │   │       │     ·"BYEL"Velocidad:"reset" %-5i                            │     │   │   \n",pokemon_velocidad(pkm_jugador));
    printf("  │   │       │                     ╦  ╦╔═╗                      │     │   │   \n");
    printf("  │   │       │                     ╚╗╔╝╚═╗                      │     │   │   \n");
    printf("  │   │       │                      ╚╝ ╚═╝                      │     │   │   \n");
    printf("  │   │       │                          » "BMAG"%-20s"reset"  │     │   │   \n",entrenador->nombre); //ENTRENADOR
    printf("  │   │       │                             » "BWHT"%-17s"reset"  │     │   │   \n",pkm_entrenador->nombre);
    printf("  │   │       │                               ·"BRED"Ataque:"reset"    %-5i  │     │   │   \n",pokemon_ataque(pkm_entrenador));
    printf("  │   │       │                               ·"BCYN"Defensa:"reset"   %-5i  │     │   │   \n",pokemon_defensa(pkm_entrenador));
    printf("  │   │       │                               ·"BYEL"Velocidad:"reset" %-5i  │     │   │   \n",pokemon_velocidad(pkm_entrenador));
    printf("  │   │       │                                                  │     │   │   \n");
    printf("  │   │       │       Gano %-30s        │     │   │   \n",ganador_txt); //QUIEN GANO
    printf("  │   │       └──────────────────────────────────────────────────┘     │   │   \n");
    printf("  │   │         GAME BOY "RED"C"BLU"O"GRN"L"BYEL"O"CYN"R"reset"                                         │   │   \n");
    printf("  │   │                                                                │   │   \n");
    printf("  │   └────────────────────────────────────────────────────────────────┘   │   \n");
    printf("  │                                                                        │   \n");
    printf("  │                            .──────────────,                            │   \n");
    printf("  │                           :    NINTENDO    :                           │   \n");
    printf("  │                            ¨──────────────´                            │   \n");
    printf("  │          ┌───┐                                                         │   \n");
    printf("  │          │ ^ │                                           .-.           │   \n");
    printf("  │     ┌────┘   └────┐                                     ( A )          │   \n");
    printf("  │     │ <    O    > │                              .-.     `-´           │   \n");
    printf("  │     └────┐   ┌────┘                             ( B )                  │   \n");
    printf("  │          │ V │                                   `-´                   │   \n");
    printf("  │          └───┘                                                         │   \n");
    printf("  │                                                                        │   \n");
    printf("  │                                                                        │   \n");
    printf("  │                         ________      ________                         │   \n");
    printf("  │                        (        )    (        )                        │   \n");
    printf("  │                         ¯¯¯¯¯¯¯¯      ¯¯¯¯¯¯¯¯                         │   \n");
    printf("  │                          SELECT         START             .   .   .    │   \n");
    printf("  │                                                         .   .   .   .  │   \n");
    printf("  │                                                           .   .   .    /   \n");
    printf("  │                                                         .   .   .    ,´    \n");
    printf("  │                                                           .   .    ,´      \n");
    printf("  └──────────────────────────────────────────────────────────────────''   MPFM \n");
    printf("\n");
}




/***
 *    ,-,-,-.                 .-,--.                  .      
 *    `,| | |   ,-. ,-. . .   ' |   \ ,-. ,-. ,-. ,-. |- ,-. 
 *      | ; | . |-' | | | |   , |   / |-' |   |   | | |  ,-| 
 *      '   `-' `-' ' ' `-^   `-^--'  `-' '   '   `-' `' `-^ 
 *
 * C: Permite cambiar los Pokémon de batalla.
 * R: Reintenta el gimnasio.
 * F: Finaliza la partida.
*/


void mostrar_menu_derrota(juego_t* juego){
    system("clear");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#                    ,-,-,-.                 .-,--.                  .                         #\n");
    printf("#                    `,| | |   ,-. ,-. . .   ' |   \\ ,-. ,-. ,-. ,-. |- ,-.                    #\n");
    printf("#                      | ; | . |-' | | | |   , |   / |-' |   |   | | |  ,-|                    #\n");
    printf("#                      '   `-' `-' ' ' `-^   `-^--'  `-' '   '   `-' `' `-^                    #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#       ⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠀        #\n");
    printf("#       ⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀        #\n");
    printf("#       ⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀        #\n");
    printf("#       ⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀        #\n");
    printf("#       ⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀        #\n");
    printf("#       ⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀        #\n");
    printf("#       ⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀        #\n");
    printf("#       ⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢿⠝⠋⠛⠛⠛⠛⠋⠉⠉⠛⠉⠝⠻⠿⠿⠿⣿⣿⠛⠉⠉⠛⠿⠿⠿⠿⠿⠛⠋⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢿⣿⣿⣿⣿⠀        #\n");
    printf("#       ⠀⢸⣿⣿⣿⣿⡿⠿⠹⠿⠿⠛⡛⠛⠉⣙⡛⠛⠛⠯⠙⠋⠙⠉⠑⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⠀⣸⠉⠉⠉⠛⠛⠛⠛⡇⢠⣿⠏⠙⠻⠿⠿⣿⠟⠃⡀⠉⢍⠙⠃⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠈⠉⠂⠀⠀⠀⠀⠀⢋⣭⣭⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⣿⠀⠀⡴⠀⡰⠀⠀⡇⢸⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠆⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⣿⠀⢰⠃⣰⠃⠀⠀⡇⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⠀⣼⣧⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⣿⠀⠀⢠⢏⣠⡠⢠⡇⣸⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⢰⠇⠘⡇⠀⠀⠀⣿⣿⣿⣿⡿⠛⢹⣿⣿⣿⣿⣿⣿⠟⠉⠉⠻⣿⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⣿⠀⠀⡏⢠⠷⢁⢸⠁⣿⡇⠀⠀⠀⠀⠀⠀⠀⠐⣷⡄⠀⠀⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⢠⠏⠀⠀⢻⠀⠀⠀⣿⣿⣿⠋⠀⠀⣿⣿⣿⡿⢻⣿⣿⠀⣀⣤⣶⣾⠏⠉⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⢹⣀⣀⣀⣋⣀⣀⣸⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⢯⠹⡆⠀⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⢠⠏⠀⢀⠀⢸⠀⠀⠀⣿⡿⠁⡰⡇⢠⣿⣿⣿⠇⠀⢻⠿⠿⠿⠟⠋⠀⠀⣰⠛⠒⢦⡀⠀⠀⠀⠀⠀⠀⢹⣀⣀⣀⣀⣀⣀⣀⣍⣁⣠⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⢹⡄⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⡏⠀⠀⡜⡀⢸⠀⠀⠀⡿⠁⡰⠀⡇⠈⡿⣿⡟⢀⢣⠸⣄⣀⢀⣀⣀⡴⠞⠁⠀⠀⢀⠨⠦⢄⠀⠀⠀⠀⠀⠙⠛⠛⠛⠛⠛⠛⠛⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⡇⢀⢼⠀        #\n");
    printf("#       ⠀⢸⣆⡇⠀⢸⠀⠃⣸⠀⠀⠀⡇⢠⠁⠀⢡⠀⢻⣾⠁⡰⠈⠆⠸⣽⡏⠉⡠⠤⠤⣀⠀⡰⠁⣰⣶⣦⢣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠄⠀⠀⠀⠀⠀⠀⢀⡏⢀⠀⣧⠏⢸⠀        #\n");
    printf("#       ⠀⢸⠘⣧⠀⠀⢰⠀⡏⢰⣦⠀⡇⡄⠀⠀⠈⢆⠀⠁⢠⠁⠀⣠⣾⣿⡇⡐⢁⣴⣤⡈⢆⢇⠀⢿⣿⣿⣼⣀⣀⣀⣀⣤⣀⠀⠀⠀⠀⠀⠀⠀⣠⢞⡏⠀⠀⠀⠀⠀⠀⢀⠞⢀⢾⠀⠉⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠈⠀⠀⢸⢠⡇⢸⠈⢇⡇⠂⠀⠀⠀⠈⢢⢀⠃⢠⣾⣿⣿⣿⡇⡇⢸⣿⣿⡇⣸⠈⢢⡬⠛⠋⠉⢩⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⢀⡜⡁⠸⡇⠀⠀⠀⠀⠀⢀⠎⠀⠎⠘⡀⠀⡠⢹⠀        #\n");
    printf("#       ⠀⢸⠣⡀⠀⡀⢸⢸⠁⢰⠀⠘⡇⠀⠀⠀⠀⠀⠀⠉⢠⣿⣿⣿⣿⣿⠁⠡⣀⠙⢋⡠⠃⠀⠁⠀⡀⠀⠀⠈⠿⢿⣿⣿⡟⠁⠀⠀⠀⣠⠋⡔⠹⠀⠣⡀⠀⠀⠀⠀⡎⠀⡘⠀⠀⡇⠰⠁⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠑⡀⠀⡄⢸⠀⢸⠀⠀⢳⠀⠀⠀⠀⠀⠀⠀⡸⣿⣿⣿⣿⡟⠀⠀⠈⠉⠉⠀⠀⠀⠴⠺⢥⣄⣀⠀⣀⣀⡤⠞⢀⡄⠀⠀⡴⢡⠊⢸⢭⣭⣭⣭⣭⡽⢯⢘⠀⠀⠇⠀⠀⠰⠃⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⠀⡇⣽⠀⡏⠀⡀⢸⠀⠀⠀⠀⠀⠀⡜⠀⢩⠟⣿⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡀⠉⠉⠉⠀⠀⣰⠋⡇⢀⡞⢠⠃⠀⢸⠀⠈⠙⠉⠉⠀⡧⡄⢱⠀⠀⠀⠀⠀⠀⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⠀⡇⢸⢰⠀⠀⡇⢸⡄⠀⠀⠀⠀⠀⡇⠀⢸⠀⣿⠀⠀⢀⡀⣄⡄⠀⠀⠀⠀⠀⠀⠈⣇⠀⠀⠀⠀⢀⡇⢀⢹⡼⠀⠇⢀⡠⠼⡆⠀⠀⠀⠀⠀⣟⣃⠎⠉⠉⠉⠉⠉⠉⠉⢹⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⠀⠇⠈⡞⠀⠸⢀⢸⠃⠀⠀⠀⠀⠀⡇⠀⢸⠀⢻⠀⠀⠈⡇⢸⠀⠀⠀⠀⠀⠀⠀⠀⡿⡄⠀⠀⠀⢸⡃⢸⢢⠁⢠⠊⠁⠀⠀⣇⣀⣀⣀⣀⣀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⠀⠸⡀⠀⢀⠃⠰⢸⠀⠀⠀⠀⠀⠀⡇⠀⢸⡀⠸⣇⠀⠀⢷⠘⢧⡀⠀⠀⠀⠀⠀⣀⡇⡇⠀⠀⠀⠸⡇⢸⠀⠑⢸⠑⠂⠤⠤⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⠀⠀⢣⠀⠎⠀⠈⢸⠀⠀⠀⠀⠀⠀⢻⡀⠀⣳⠖⠙⢦⣀⠈⠑⠶⠛⠛⡉⠉⠻⣾⠥⡖⠉⢧⠀⠀⠀⡇⢸⠀⠀⠸⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⣽⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⠄⠀⠀⠳⠀⠀⠀⢸⠀⢐⣒⣻⣍⣀⡀⠙⢓⡇⠀⠀⠀⠉⠓⠲⠶⠒⠋⢻⠀⠀⢱⣠⣽⠠⠞⠉⢳⢠⡇⠀⠀⠀⠀⠀⠉⠉⣶⣶⣶⡶⠦⠤⡼⡧⢀⣀⣀⣀⣀⣀⣀⣀⡞⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆⠀⠀⡜⢳⠀⠀⣀⣀⠷⠤⣤⡤⣤⣤⣤⣤⣤⣤⣾⡆⠘⢉⣠⣿⣤⠤⠖⠋⢸⠁⢸⠀⠀⠀⡀⠀⠀⡏⠁⠀⡇⢀⠜⠁⡇⢸⣿⠿⡇⠀⠀⣠⠏⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⢸⠀⠀⠀⠀⠀⢰⠀⣇⠀⢸⠁⠸⡆⠈⠉⠉⠉⠀⢸⠀⣿⠘⠉⠙⢿⣿⣿⠛⢻⠛⣿⣿⣿⠒⠒⢛⡏⠀⠂⠀⣀⢔⠇⠀⠀⡇⠀⣠⠟⠁⠀⠀⡇⢸⠒⠝⠇⢀⡴⠃⠀⣠⢻⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⢸⠀⠀⠀⠀⠀⠈⡆⠘⣆⡇⢸⡄⢳⡀⠀⢀⡄⠀⢸⠀⣿⠀⠀⠀⢸⣿⣿⠀⢸⠀⣿⣿⣿⠀⠀⠊⠀⠤⠒⠊⢁⣞⡀⠄⢀⡿⠞⠁⠀⠀⠀⢀⡇⠈⠀⠀⡰⠊⠀⠀⣰⠃⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠐⠀⠈⡄⠀⢀⠀⡄⠀⠘⡀⠘⠃⠸⢡⠀⢧⢀⢾⡇⠀⢸⠀⣿⠀⠩⠄⢸⣿⣿⠀⢸⠀⣿⡿⣿⠀⠀⠀⠀⣀⣀⣀⠈⠁⢀⡴⠋⠀⢀⠰⢺⠀⠀⢸⡇⠀⣠⠊⠀⠀⠀⢠⠃⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠄⠀⠃⠀⠘⠀⠰⠀⠀⠘⢄⠀⡆⠀⠣⠈⠿⠸⡇⠀⢸⠀⣿⠀⠀⠀⢸⣿⣿⠀⢸⠀⢻⡇⣿⠀⠀⠀⢐⣒⣒⡒⠀⡰⠋⠀⠀⡠⠊⠀⢸⠀⠀⠘⣇⡜⠁⠀⠀⠀⣠⠃⠀⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⠀⠘⡀⠀⠣⠀⠁⠀⠀⠀⠙⠀⠀⠀⠑⢄⠀⢇⠀⠘⠒⢛⣀⣀⣀⠈⠉⠹⠤⠼⠀⠘⠓⠛⠀⠀⠀⠼⠯⠀⢀⡞⠁⠀⠀⠔⠀⠀⠀⠈⢄⠀⠀⠋⠀⠀⠀⣠⠞⠁⠀⠀⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠀⠀⠒⠶⡶⠖⠒⠀⠀⠀⠀⠀⠀⠀⢐⢒⣒⣒⡒⠂⠀⠀⡼⠁⠀⠀⡜⠀⠀⠀⠀⠀⠈⢢⡀⠀⠀⡠⠊⠁⠀⠀⠀⠀⠀⢸⠀        #\n");
    printf("#       ⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⣛⠏⠉⠀⠀⠀⠒⠒⠒⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⢰⠇⠀⠀⢠⠀⠀⠀⠀⠀⠀⠀⠀⠘⠢⠎⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀        #\n");
    printf("#       ⠀⠘⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠚⠛⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠚⠒⠒⠒⠚⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠚⠀        #\n");
    printf("#                                                                                              #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#   Su Party ha sido derrotada, pero eso no significa que usted haya perdido. Usted puede      #\n");
    printf("#   cambiar su Pokemon y reintentar el gimnasio, derrotar al entrenador que te gano y seguir   #\n");
    printf("#   tu aventura para converitrte en un Maestro Pokemon                                         #\n");
    printf("#                                                                                              #\n");
    printf("#   Ingrese:                                                                                   #\n");
    printf("#                                                                                              #\n");
    printf("#   - 'C' Cambiar Pokemon                                                                      #\n");
    printf("#   - 'R' Reintentar el gimnasio                            - 'F' Finalizar la Partida         #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
}



/***
 *    ,-,-,-.                 ,.   ,.     .                
 *    `,| | |   ,-. ,-. . .   `|  / . ,-. |- ,-. ,-. . ,-. 
 *      | ; | . |-' | | | |    | /  | |   |  | | |   | ,-| 
 *      '   `-' `-' ' ' `-^    `'   ' `-' `' `-' '   ' `-^ 
 *                                                         
 * T: Toma un Pokémon del líder y lo incorpora en los Pokémon obtenidos del jugador.
 *       - Una vez realizada dicha operación, esta opción desaparece del menú.
 * C: Permite cambiar los Pokémon de batalla.
 * N: Próximo gimnasio.
 *       - Si no hay próximo gimnasio, se deberá notificar al usuario que se convirtió en Maestro Pokémon.
*/


void mostrar_menu_victoria(juego_t* juego){
    system("clear");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#                     ,-,-,-.                 ,.   ,.     .                                    #\n");
    printf("#                     `,| | |   ,-. ,-. . .   `|  / . ,-. |- ,-. ,-. . ,-.                     #\n");
    printf("#                       | ; | . |-' | | | |    | /  | |   |  | | |   | ,-|                     #\n");
    printf("#                       '   `-' `-' ' ' `-^    `'   ' `-' `' `-' '   ' `-^                     #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#                         ⢀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⣠⣤⣶⣶                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢰⣿⣿⣿⣿                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣀⣀⣾⣿⣿⣿⣿                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⡏⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠁⠀⣿                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠙⠿⠿⠿⠻⠿⠿⠟⠿⠛⠉⠀⠀⠀⠀⠀⣸⣿                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣴⣿⣿⣿⣿                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⢰⣹⡆⠀⠀⠀⠀⠀⠀⣭⣷⠀⠀⠀⠸⣿⣿⣿⣿                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠉⠀⠀⠤⠄⠀⠀⠀⠉⠁⠀⠀⠀⠀⢿⣿⣿⣿                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⣿⣿⣿⢾⣿⣷⠀⠀⠀⠀⡠⠤⢄⠀⠀⠀⠠⣿⣿⣷⠀⢸⣿⣿⣿                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⣿⣿⣿⡀⠉⠀⠀⠀⠀⠀⢄⠀⢀⠀⠀⠀⠀⠉⠉⠁⠀⠀⣿⣿⣿                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿                                  #\n");
    printf("#                         ⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿                                  #\n");
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
    printf("#   Presione:                                                                                  #\n");
    printf("#                                                                                              #\n");
    printf("#   - 'N' Pelear el Proximo Gimnasio                          - 'C' Cambiar Pokemon            #\n");
    if(!gimnasio_pokemon_tomado(juego->gimnasio_actual)){
        printf("#   - 'T' Tomar Pokemon del Lider                                                              #\n");
    }
    printf("#                                                                                              #\n");
    printf("################################################################################################\n");
    printf("#                                                                                              #\n");
}



void pantalla_maestro_pokemon(juego_t* juego){
    system("clear");

    printf("   ooo        ooooo                                  .                           ooooooooo.             oooo                                                          \n");
    printf("   `88.       .888'                                .o8                           `888   `Y88.           `888                                                          \n");
    printf("    888b     d'888   .oooo.    .ooooo.   .oooo.o .o888oo oooo d8b  .ooooo.        888   .d88'  .ooooo.   888  oooo   .ooooo.  ooo. .oo.  .oo.    .ooooo.  ooo. .oo.   \n");
    printf("    8 Y88. .P  888  `P  )88b  d88' `88b d88(  \"8   888   `888\"\"8P d88' `88b       888ooo88P'  d88' `88b  888 .8P'   d88' `88b `888P\"Y88bP\"Y88b  d88' `88b `888P\"Y88b  \n");
    printf("    8  `888'   888   .oP\"888  888ooo888 `\"Y88b.    888    888     888   888       888         888   888  888888.    888ooo888  888   888   888  888   888  888   888  \n");
    printf("    8    Y     888  d8(  888  888    .o o.  )88b   888 .  888     888   888       888         888   888  888 `88b.  888    .o  888   888   888  888   888  888   888  \n");
    printf("   o8o        o888o `Y888\"\"8o `Y8bod8P' 8\"\"888P'   \"888\" d888b    `Y8bod8P'      o888o        `Y8bod8P' o888o o888o `Y8bod8P' o888o o888o o888o `Y8bod8P' o888o o888o \n");
    printf("                                                                                                                                                                      \n");
    printf("                                                                                                                                                                      \n");
    printf("                                                                                                                                                                      \n");
    printf("     » Felicitaciones %s eres un verdadero MAESTRO POKEMON \n",juego->personaje->nombre);
    printf("         » Obtubieste %i medallas\n",juego->gimnasios_derrotados);
    printf("\n");
}




void easter_egg(){
    system("clear");

    printf("@#############################################################MMMMMMMMMMMMMMMMMMBBBBMMMMBB&AMBAHM###MMMMMMM# \n");
	printf("@hG&&AA&&A&G&&&&GG&AA&&&&&AAAAAA&&&G&&&GGhh&AAAG93XX39h93X225iiiS5SSSSSSSiSiSSisssssiisssi:.;s;iXX25Sii25SSA \n");
	printf("@hAAHAAHAHAAAAAAAAAAAAAAAAAAAAAAAHHHAAAG&&3Ssi5G&GG&&GG9333X2552222222255525rrSSS55SSSiSS5X;:Xri2SX252r ;A9A \n");
	printf("@GAHHHHHHAAAAAAAAA&AAAAAAAAAHHHAh25iiS29B@Hr   sAX9GAAGh3333XX22222XXX5iS55Sii552225SS2X2iih&A: ,;X22r:;:ihA \n");
	printf("@GAAHHHHAAAAAGG&&&G&&&AA&AA&XSsii55Sirrrs&@#r   s::::r53h9XX3X252252XX2SiiiiS55525SS5irr239GGAHX39222XA3,:hA \n");
	printf("@3GAAAAA&AAAA&GGGGhhhGGGGG2i2hAAhir;:.    G@9   .;....:;rr53X25SS5552225rrisiSSiiiiiiir:Shh9999;iX223G&hAA9& \n");
	printf("@29&G933GAAAAA&Gh933393&MMM#@HXs:,:,,     ,@@,   r,     ,;;;r52SiiSiiiiisrsiissssrsssSXh399X2222222X99hGAHh& \n");
	printf("#5XX2X999hhGGGGGh33XXX2B#AH#MGir:::,,.     r@A   ,r        ::,:iSisssrrsssssssrrrssss5X3XX2222riX2X3333G5.;& \n");
	printf("#iS52XX222222X99993XX2X##323HMB9Sr;;;,      &@;   s,         ;;.:srsssrrrrrrr;r;rrsiSS5522252222X3333X3h2:rG \n");
	printf("#iS22255225222XXXXXXX5G@#X3#AGAB#A2rrr;,    ,@A.  ;s,        .AS ssrssrrrrrrr;rrrssiiSSiS555222sr9XXX339GA3G \n");
	printf("#s52222222552XXXX22225M@Ai####H3X3hAAG2i;,  ,#@r. :Sr.      ,;; ,srrr;rr::;;;rrrrssiiiiSS55222XSs22S2399332h \n");
	printf("#s522222255SSSS22252SX@@2;MAX29H#B&XS2HA&32ssA@X;:;Xs;::;sirr::r5rrrr;;;:::;;rrrrrsssssiSSSri3X95S3X33XXXX59 \n");
	printf("#s5X22222255SiiiSSSSiA@@;5#Xr;;;r5&MMH@#3S5H&B@@2:,SMhSSi:i2ss;.rsrr;;;;;;;;rrrrrrsssii5252rsXXis933X22XX2i3 \n");
	printf("#i52222222225SSiiiiis#@B:HMXs:,,,...:r2B@@##AA@A;.. @@A2Sr;,   .ssr;;;;;;;rrrrr;,,rsiSSi:rX3X23i;XX255225SsX \n");
	printf("#i52222222225SSiiisr5@@&r#HXr;::        .;h@@@@G:   #A:,       rSr;;;;;;rr;rrrr;..riSi,;;;2X22X9hXX2555Siir2 \n");
	printf("#i5XXXX2222555Siiis;A@@9i#G2ir;;,.         :A#@A.   A;        .ir;;;;;;rs;:rrrrr::sSiS;;93X2X922X2225SSiiir2 \n");
	printf("#i2XXXXXXX2255SSiirr##@3XB35Siii;:,..       h#@h;. ,B,        :r;;;;;;rrrrrrrrsi;r5iS232Sr.i2r;;25,:2, s5is2 \n");
	printf("#SX9X33XXXXX255SisiB@##&&AX2SiiSi;;:.      ,A#@X;  ;A.      ..;r;;;;rrrrrrrrrsr;ri22222Si::X5,r5Ss:rSr;sr  X \n");
	printf("@23h333333XX225SirB@###AH&X2ssrrs;;:...,.  rA#@5;, X9,      . rr;:;rrrrrrrrrsisrSrr55522X5iiX32SSss5ir2srrrX \n");
	printf("@39hhhh9333XX25isr#@MGB#M&2irr;;;::;,,,,:,,iH@#i:, A2:,,.    .rrr;;rrrrrrrrrsriS5s;5SS5irX2525iiS5SSSSSS5X23 \n");
	printf("@X9GGGG993XXX2Siri@##s:A@#G5sr;:,::::;:,. .5#@Mr:,,BS;;:,  .,;rrrr;;;;rrr;rssrsiS5iriSSSS55SiiiSiiiSSiiS22SX \n");
	printf("@XhG&&GGh93X25Sir9@#B9XAH&#@HXi;:,,,,,,,,,;G##A;:,iMrrr;:..:rirr;;;;,;rr;,r;;siiiir;iiiiiiiiiSSiiiSSSiS2XXiX \n");
	printf("@3h&&&GGh93X25Sir3@#HhA@M2:;B@@#AXr,.,,,, :A##3;;;AHsr;:;rr3X:r;;;;;;rr;:rrrrsrssssiiisssssiiiiiiSSSS22XX2iX \n");
	printf("@3h&AGhh9XXX25Sir3@##&B#AGhsi2A#@@@#Ah9&hi2##M3r;r#Mh95i9A&2 ,;;;;;;;;;;;;rsisrrrrsssrsssssissssiiSS52XX25s2 \n");
	printf("@3GA&Gh933X225Si;&@#AAM##Gi;..,:;;rS3GH#@@@@##@MB#@MAHBH&S: :r;;;;;;:,:r;;;,..rrrrrrrrrr,;ssrrsssii552225Sr5 \n");
	printf("@3GGGGh993X22SSi;X@MGAAXG#BS:.            :9M2:,,2@r.;;,    ;;;::::;,:;;;;:   ,:;;;;;;r;;rr;rrrsiiiS55SSSirS \n");
	printf("@3hhhhh93XX25Sis;&@MBBAr.rH@#hr,          i@#X,  :Mr.      :;:,:::::,:;;;;;;rr:,:,;;;;;;r;;,;rrrsssiiiiiis;S \n");
	printf("@X39h9933X22SSisrM@MAH#M9iX@@@@B5r:,     .i@Hr:  rs    .;: ;;s222srrr:,,,::::;:,:::,;. :;;;;;;;;rrrsrrrsrr;i \n");
	printf("@X99993XX225SSiri@#AXAMM#BXh@@@@@@@@#BGX2SAM#&;rXG;:SB@@@sr2M@@#2:sXAHhi;;;;r. ;;::,,,,::,,:;iS23h22s;rr;;:s \n");
	printf("@X993XXX225SSisr3@#BAHBXSX2;;h##@@@@@@@@@@#M@#X&@@@@@@@H. ;G@MB&;;2isS9HMHA3i:;XHMXis,,:,;S&&3##H2;:,:::,::s \n");
	printf("@X393X2225Sii35s&###BMM3sr;r5H#&ii5GMBAM@@@#@@H@@@Hr. ;i  r##GGr ;srr;;,, :. :rsXM92@HGA#@@2 .hH&G&hX5i593SS \n");
	printf("@2X3XX225Sii2#@@#HH###Mh2i;,;HAs:.   ,,,:5ABX;,.Xi     2 2@A&G3Srrrr:::,,:::,,;iAAM@@@@@#HH3iGG99h&H##AX;, r \n");
	printf("@2XXX22SS2A#@@@@##M###M&hhiri#&:.,      :A@Bi:  ;r    i:5@B3sX25ir;;:,,,,,,,:.:sS&h#@@#MHA&AHGXXX3hhG&3srr;s \n");
	printf("@2XX255XhM@@@@#######@@#HAhX&@Hr:;:     .H@X:is;r:.  :S5@MGr.:;;:,:r;;r;,. .:. s2H@#@@MA&G&&Ss33333h99G&GH#A \n");
	printf("@2Xh93MBA@@@#######BB#@@@BAAM#AXi;rr.   .A@9:,::r:.  S3#AX;,.. .,,.:s;,:,, .rs:2A@@Mr;GAGh9h;:3XXi.S33GAA&3& \n");
	printf("@X2Si29A@@########B95XB@@@BBB#B&&Srs;  .S#@MA2;rr.  :MAGs:,.,,,,::, ,:.:r5r;9A2XM@#&..&BAGG&A&933X2X3X9hAHHH \n");
	printf("#3h2SisSB#BBM##M###A52M#M@##MH&3Xir;:,,;X@#i;;:S;  .HH5i, .,:,::,;, .;;s2939#H9A@@#@@@BG9X999333339X222X9hGH \n");
	printf("#2M###A9XBMM#BHBMMMAA##AXG@###ASr;;;:,:;3#3;:,;G;,:AArrr..::;,;:.:;,rh5s9AAM#A&##HHHHAh3XXX3GG3393X2X3X2252A \n");
	printf("#sA#M#@#AA#@#&AHAHHH##HA5.:M#3A@hr;;::,:9MAi5,S2:;Ghr;s;,:;:;:;;;;rr3hiiAHAAAXA#MBHAAh9hhGGs :XG9339Gh3XX99A \n");
	printf("#iGA2hHMBHHAGGAAGGH#@BAB3  i@@r:M@9r::,:9#B:,:&r;A2s;rssr;;;::srrss5hXiXABBBHB@MHA&AA&&&&&&i  iAhGAAG3XXX39A \n");
	printf("@2AHir59MB5rsXAMBAM#AGGAX:;Ar.s, rGM9r:sX#G;.2@BGX;r,;i32iir;r5r5X2AAS2#@@####MMBAGGGX23X9&AMHA&&GhhX22XGAAB \n");
	printf("@GHAirShHASi2&&AAAAA99hXsiMG  .9#G&@@@#@##B2r@#Ss;;: ,iXXXh2rhh2&GAH2SM@@###MHAAAAhh99h&HiiBHHA&Ghhh9GAAHAAB \n");
	printf("@AAA9GHAHMHBBAhGA&H@BGHHA@@5SB@@@##MBMMBHAB&Xr,,,,;,.rXrShh5S9SX3G&s5@@@#MBHHHAA&GAAAAHAA99BAA&&GGGh3hGAAAAH \n");
	printf("@9&HMBBAMBMBAhAA93&BHGGhAB#M@@M35sr;;:;rSXX;.  ,.,;:;X&S9XsrsriA@A;s@@#MMMBHHHHBh;X&&&AX;iHG&&&GhhGGAAAAAHHM \n");
	printf("@9AMMMBAhX523&AXS2hhXXhhXX9GGh5srr;;::;i93r:.:2SrS35iA&GAi;r5SH#5:i@@#MBBB#MBHBBM9BBA22BMBAGG&AAHMBAAG9hh&AB \n");
	printf("@GGAA32sr;;sSii2XG9irS5522X3XX99hGA&&9hAhS;:;X9siA&52A222Si3AA2;i33@#ABMBH&GHHX3BHM##MX9&AHBHHB#@G3HH&G93X2A \n"); 
	printf("@#H&h333335iiiXX3S;;ihSsi5X9hhh&A&G9GGh2sr;rAA22h5:;3HA3i3MBAX9@@@##BBM2hMS9HHSriAsGBM#BAGAHMM#2   .GAHAAGXA \n");
	printf("@BMMM#MAAA9Xh&3h2si5XG5sr;;rsiisssiSirrrsrXBA9GA5::2H9&A2SXG#@@@@@##MBM55MHM##@@#@#G&AHHAAAAB@s     G#AHAHBB \n");
	printf("@&ABB#####HH&X399G3X22iS5Sr:;;::sSSs;ri52GH&h3X2SXG95r:,sA..:s9A#@@#@MM@@M###@H.  2@MAAHHHB##   :;sA@@#BHA&B \n");
	printf("@&A&AHBM#@@@@MHAGGh3222239X25ShMX552hHHB#@#&GAHMBG5r:,s#@X.:;;;2@@BB##@####MM@     S@@#####@B    ,X@@##MMBAB \n");
	printf("@A&HBHMMBH##@@#MMM##@@@A9A#HG@@@@GAHH#@#&X5SsiXS;,  :B@@r .... r@G;H@####BMB#@: ,rr;2@@@@@@@@2;sH@#@@MMMBBAB \n");
	printf("@AB#HAHBBH2G2S5X3933hAMMAGX5s#@@@s;rr;::...       .9@@X            S#@#####M#@@  ,rs.r@@@@#2s:rG@@#@##HBBBAB \n");
	printf("@HMM359GAirs;;rr;;;;:::::,,, G@@@:             ,2H@@M.           :, ;H@@#####@@@  ;Si;X; s.     i@#&B@MHHHAM \n");
	printf("@ABX2@&s;:;;rr;::,,.         #BA#,           2@@@BBB       .  :rrSir;:9@@#####@@@..;;2r   i   ;2M@#H#MHHHHAB \n");
	printf("@&Xrr9@@B2r;,.,...          r@93M;         ;#@#BBXr               ....:H#5M###@@2.;;.;r.  S#AGH@@MHHM@#BAHAB \n");
	printf("@r;sirS@@@@@&:  ...   ..... ,@AA#H        h@@BA#s                  .,, ;Hi#@@@3      r92:GG@@@@@@#&M#HBMMA&B \n");
	printf("#r532i;:A@@@@@5 .,:::;;:,.. 5@HH#@,     ,HB&AA#2                     ..,r.  2@.    . ;A#HB@@@@@@@M@B##MAGHBB \n");
	printf("#S22i;;,.:i@@@@@r,          ,@#M#@@    5@@AhAA:                      ...     Xr    :, 3M3s@@@@#M@#@BH#HH#MhH \n");
	printf("#iiirrr;:.  2@@@@@&s:   ..   B@#@@@; .B@Bh9A9                        ,,r..r. ,A;  .r. ,2AAM@@@@@@M@AA99MAMHM \n");
	printf("#sssssrr;:,.  3@@@@@@@;     5@3rrsX#@@@A3r2&                .,    ...,r:rh,   XA;:,.   r&MM@@#@@H#A&H929G#AB \n");
	printf("@iSisrrr;;;,.  r@@@@@@@@&Sh@B,    ..:s&#B&M                 s&;  .:r;2,  i2rsX; ,5;2hs;XGH#@@@@MM#BB#9hhX&5A \n");
	printf("#iSisrrrr;;::,   ,r9@@@@@@@2.,;;;;rr:..i#@5           .  ..  :XBX;  :;.   ;Air;,s:,H@@@M#h 2@@@@@#A@B&#3&3SA \n");
	printf("#iiirrr;;r;;:,       ,A@@@M;5X222H@B3ir:3@#2AHHAA&GG9#r .  .9hA@@#9s  ;r.  .2,r@@A5X3@@#@#.  5@@@@@@@@@#HAXA \n");
	printf("@SSiisisr;;:,..        :#@#H@@BHHA@@@@@, M@@@@@@@@@@@@#&i  :;2@@#B@#X;  ,   ,sH#A#@#XG##AB@X    .;Sh&@@@@B&A \n");
	printf("@XXXXXSr;:::,,:::::,,:;rH@M@@@#35A&s29i,,@@#AM@@@@@@@@@@@@@5   .  .#@@s , ,. .H@@HhX3HMH3S5#@B;        s@@#H \n");
	printf("@&&h2s;;;;;;;;r;;r2H@@@@@@XhHMhGA@2;59GA9@@@MGSr;:,,,,,,r#@@#s: ,   r@@#@53:s,A@@@#AAHHhXi:,s@@#r        2@# \n");
	printf("@XXSrr;;;rrsrrS&@@@@@@@@@@M&AHB#@#&hGG92r2@s               9@@@Ar .  .A@@@@#@###M###MBAh99i;.,5@@X:,   :. :@ \n");
	printf("@iissiissiS3M@@@@@@@@@@@#@@G&hG#MMHA2r;:,h#B5                S@@@#&:rAB@@@@@@@##A&&ABMHh3GGS;. .3@B;:;, sA,X \n");
	printf("@issS252&#@@@@@@@@#H3Sr.,#@2isssi2;::,.:h#AH@@i                ,9@@@@@@@@@@@@@#A3X3&H#MHAGh2s;.  ,9#5,;;.;AG \n");
	printf("#rs552B@@@@@@B9Sr;:..  ;@@@#Srr;:,,,.,&HBA59H#@B.                 .2BX,   ,2AB##&iiX39HMHHh32r:.   .9#r.,:5h \n");
	printf("#59A@@@@@B3ir;:::,:::,i@@@@@@@GSsrrs3@9  . 5#MM@@i                           .iH@AsrssSAHA#A&2;,     ,AG;2;r \n");
	printf("@h#@@#&2isrr;;;:;;;r;r@@@@@@XA@@@@@@@,     .i@@#@@#:                  ..,.,::..rh@#XsrrSAAG@BAs:,      r@@ : \n");
	printf("@AMHhX2Ssrrrrrrssiii9@@@@@@r  :@@@@@A  ..    .M@@@@@&;                 .,,;;rrr;S5##S;;riA3X@#As:,     :@2 . \n");
	printf("@AA&32irrrrsi5222iS#@@@@@@r ,..@@@#@A ...      ;hM@@@@@X                    :r25is;##, :;sBS2@#ASr:::,:h&  : \n");
	printf("@GG32Siiii52X22i;2@@@@@@9. ..  ##AA#5              r@@@@@;   ...       .... ,;s5X:;;#A  .;s#i5#HG2iss2M&.  : \n");
	printf("@9hh3XX39h925Ss;A@@@@@X.   ..  S@BH#2                A@#@@h      ......  ..:;rrsX: r:#A   ,;#r2#AAAM@@2: . i \n");
	printf("@&HBHHHAGXSsssr#@@@@h,  ,:::;:..@@@@@ .,,,,.....      ;h@@@@,        .:::....;siri, ;,#H,   :M;A#B#@3;;:r,;@ \n");
	printf("@A##BHAGX55SSr2@@@A;,:riiSiiisr,r@@@@i,;;;;:;;,,:;::,   .s#@@A         .:;rr:,:;;i@,ii,MHr,:rB#i#@9r:,.r,;@@ \n");
	printf("@A##BA&9X2225rB@@G:ri522222255ir:@@@@3;s;ssrr;,.,,,.        i@@2,...     .,;iSi;:r@@@@S,&h&@@#@##M2i  ,:X@@# \n");
	printf("@&HMHG3Xisiir#@&s:;rssrrr;::;r;;,&@@@G.:,,..                   S;.,,:,,.    ,r3&3rB@#5@h;rs9@#&32A#HSsG@@@XH \n");
	printf("@&AB&3X2Sssri@s .,:::::::,  ,,,. 5@MG.        .,,::,:::::,..         .,,::::::;i2X@@#;s@#XS::53XS2M@@@@@MMAA \n");
	printf("@AHA&G325Sisir,:::,,,,,..         @@9     ,;;;rsis;rr;;::,...........   .:rirr;rr;9@@@H#@@@MAM@@@@@@@@@@@MB# \n");
	printf("@h3XXX333X2ir;;;;;;;;;:,,,,,,...  A@@,;rsiiSSiiiir..:,..             ..,:;;;;rsiri&###@#@@@@@@@@@@@@@2r293iH \n");
	printf("#255issiiSSSiisr;;;;::;,:;;;;rrrrriBHsssi;,;rrrr;;;:::,,,..            .,::;;rrrs2BMBMMMMBMM#@@@@@@@#9XS292A \n");

    detener_tiempo(10);
    system("clear");
}


void mostrar_pantalla_derrota(juego_t* juego){
    system("clear");
    if(!juego){
        return;
    }

    /**/                        
    printf("                                                                   ▓█████▄ ▓█████  ██▀███   ██▀███   ▒█████  ▄▄▄█████▓ ▄▄▄                                                   \n");
    printf("                                                                   ▒██▀ ██▌▓█   ▀ ▓██ ▒ ██▒▓██ ▒ ██▒▒██▒  ██▒▓  ██▒ ▓▒▒████▄                                                 \n");
    printf("                                                                   ░██   █▌▒███   ▓██ ░▄█ ▒▓██ ░▄█ ▒▒██░  ██▒▒ ▓██░ ▒░▒██  ▀█▄                                               \n");
    printf("                                                                   ░▓█▄   ▌▒▓█  ▄ ▒██▀▀█▄  ▒██▀▀█▄  ▒██   ██░░ ▓██▓ ░ ░██▄▄▄▄██                                              \n");
    printf("                                                                   ░▒████▓ ░▒████▒░██▓ ▒██▒░██▓ ▒██▒░ ████▓▒░  ▒██▒ ░  ▓█   ▓██▒                                             \n");
    printf("                                                                    ▒▒▓  ▒ ░░ ▒░ ░░ ▒▓ ░▒▓░░ ▒▓ ░▒▓░░ ▒░▒░▒░   ▒ ░░    ▒▒   ▓▒█░                                             \n");
    printf("                                                                    ░ ▒  ▒  ░ ░  ░  ░▒ ░ ▒░  ░▒ ░ ▒░  ░ ▒ ▒░     ░      ▒   ▒▒ ░                                             \n");
    printf("                                                                    ░ ░  ░    ░     ░░   ░   ░░   ░ ░ ░ ░ ▒    ░        ░   ▒                                                \n");
    printf("                                                                      ░       ░  ░   ░        ░         ░ ░                 ░  ░                                             \n");
    printf("                                                                    ░                                                                                                        \n");
    printf("\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣶⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⢿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  \n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠙⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀      __   ___                                         __     __   __       __ \n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠙⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ /\\  |__) |__     \\ /  /\\     |  | | |\\ | |\\ | | |\\ | / _`   /__` /  \\ |\\ |  _|\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⡇⠀⠀⠀⠙⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀/~~\\ |  \\ |___     |  /~~\\    |/\\| | | \\| | \\| | | \\| \\__> . .__/ \\__/ | \\|  . \n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠙⠻⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                                           '                   \n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠈⠹⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣤⣶⣶⣦⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  Gimnasios Derrotados: %i/%li\n",juego->gimnasios_derrotados,heap_elementos(juego->gimnasios));
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⠋⠀⠀⠀⠈⠉⠙⠛⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣽⣏⣀⣀⣤⣤⣤⣴⣶⣾⣿⣷⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣆⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  Le deseo mejor suerte en su proxima "BRED"AVENTRURA POKEMON"reset"\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⠛⠛⠛⠛⠋⠉⠉⠉⠁⣀⣀⣉⣤⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠻⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠙⠿⣿⣿⠿⢿⣿⠿⠿⠛⠛⢛⣛⠛⢻⣿⠀⠀⢀⣀⣤⣴⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣿⡇⠀⠈⠛⠀⠀⠀⠀⠙⠋⠀⢺⣿⠀⣰⡿⠛⠉⠁⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⢿⣦⣤⣤⣤⣤⣤⣤⣀⣼⣿⣴⡿⠁⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣷⡄⠈⠉⠉⠉⠙⠛⠿⢿⣿⣿⣿⣮⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣆⡀⠀⠀⠀⠀⢠⣶⣿⠟⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⣷⣶⣶⣶⣿⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣃⣀⣀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⡟⢹⣿⠟⠛⠻⠿⣷⣶⣤⣤⣾⣿⣿⣿⣦⡀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠟⠁⢸⣿⠀⠀⠀⠀⠀⠀⠉⣹⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⠇⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⣿⣷⣶⣶⣿⠟⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⠏⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⡟⠀⠀⠀⠀⢸⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⠇⠀⠀⠀⠀⢸⣿⣿⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣴⣶⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠘⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡿⠇⠉⢼⣟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⠀⠘⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⣼⡟⠀⠀⠀⠀⣠⣤⣶⣶⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⡏⠀⠀⠘⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⣿⡇⠀⣀⣴⣾⣿⣿⠏⠀⠙⠻⣿⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⠃⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⣿⡇⣾⣿⠋⣿⣿⣿⣄⠀⠀⠀⠈⠙⢿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣴⣾⣿⣿⣿⣿⣶⣶⣶⣦⣤⣤⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡟⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣷⠀⠀⣿⣇⣿⡇⣴⣿⣿⣿⣿⣷⣴⣦⣶⣷⡄⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⠋⠀⠈⠙⠛⠿⠿⠿⠾⢿⣿⣿⣿⣿⣿⣦⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⠀⢀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣧⠀⢸⣿⣿⠀⢻⣿⣿⣿⣿⣿⠉⠁⠈⠉⢙⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢴⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⣿⣿⣾⡟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠾⠿⠿⠿⠿⠻⠿⢷⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⢸⣿⣿⡀⠈⠻⢿⣿⣿⠏⢀⣴⣶⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣄⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠉⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣀⢸⣿⠻⣿⣷⣤⣀⠀⠀⠀⠙⠛⠉⣨⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣾⠟⠛⠛⠛⠋⣿⣷⣶⣦⣄⣀⣀⡀⠀⠀⠀⠀⠀⣿⡏⠠⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣦⣄⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⢸⣿⠀⠀⠙⠛⠿⠿⢿⣷⣿⣷⣾⠿⠋⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⢉⣙⣿⣿⣿⣶⣦⣤⣶⣿⣿⣿⣿⣿⣿⣿⢿⣷⣦⣤⣀⠀⣿⣧⣄⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣧⡀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡼⣿⣇⠀⠀⠀⠀⠀⠀⢺⣿⡄⢀⣀⣠⣶⣾⡿⠿⠿⠿⠛⠛⠛⠛⢛⣛⣛⣛⣛⣛⣿⣿⣿⣿⣿⣯⣭⡛⠛⠿⣷⣾⣯⠛⢿⣿⣿⠟⠻⢿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣦⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⠙⣿⣇⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣷⣶⣶⣶⣶⠶⠿⠿⠿⠿⠛⠛⠛⠛⠛⠛⠛⠛⠋⠙⠻⠿⢿⣿⣶⣾⣾⡿⠀⠈⠻⣿⠀⠀⠀⠉⠛⠻⠿⣶⣦⣄⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣷⣄⠀⠀⠸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣾⣿⣷⣶⣶⣶⣤⣤⣤⣬⣽⣿⣿⣿⣦⣤⣤⣀⡀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠿⢿⣶⣤⣤⣄⡀⠀⠀⠀⠀⠀⠈⢙⣿⣿⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠿⢿⣦⣠⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⢿⣿⣿⣉⠉⠉⠉⠉⠙⠉⠙⠙⠛⠉⠛⠛⠛⠛⠿⢿⣷⣶⣶⣶⣶⣦⣤⣀⣀⣀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠙⢛⣿⣿⣶⣾⣿⣾⣿⠿⢻⣿⡄⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣾⣿⢻⣿⣷⣦⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣦⣤⣬⣭⣽⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠿⠿⠶⠆⠀⠀⠀⠀⠀⠀⠀⢿⣯⠀⠀⠀⠀⠀⠀⠀⢻⣷⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⠏⣿⣧⠈⠋⣿⣿⣿⡿⠉⠉⠉⠁⠀⠈⣿⡿⢹⣿⡏⠀⠀⠀⠈⢩⣿⣿⠁⠀⠀⠙⠻⣿⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⡇⠀⠀⠀⠀⠀⠀⠘⣿⣇⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⠇⠀⢸⣿⠀⣾⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⣿⡇⠀⠀⠀⠀⣸⣿⣿⠀⠀⠀⠀⠀⠀⠈⠻⣿⣆⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣧⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠘⣿⢶⣿⢿⡇⠀⠀⠀⠀⠀⠀⠀⢠⣿⣇⣠⣿⡇⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⣷⡆⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣤⣤⣤⣿⣿⡟⣿⡇⠀⠀⠀⠀⠀⠀⠀⠘⠿⠛⠛⠿⠃⠀⠀⠀⠀⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠿⠏⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⠉⠉⠉⠉⣿⣷⣻⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⠟⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⡿⠿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("\n")
}
