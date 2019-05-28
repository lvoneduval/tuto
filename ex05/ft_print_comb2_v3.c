void ft_putchar(char c);

void print_a_comb(char dizaine1, char unite1, char dizaine2, char unite2)
{
		ft_putchar(dizaine1);
		ft_putchar(unite1);
		ft_putchar(' ');
		ft_putchar(dizaine2);
		ft_putchar(unite2);
		if (dizaine1 == '9' && unite1 == '8')
			return ;
		ft_putchar(',');
		ft_putchar(' ');
}

/* 
 * On passe certaines "instructions si une condition est respecté" dans les if.
 * Je vais m'expliquer mais pour ça 4 règles à connaitre sur le fonctionnement du C:
 *
 * /!\ spoiler alerte:
 * C'est la partie la plus longue du tuto, tu passes cette etapes, le reste n'est que futilité.
 * Je vais peut-être (et même sûrrement) expliquer des trucs que tu connais déjà.
 * Mais bon je vais les expliquer quand même on sait jamais.
 *
 * 
 * 
 * 1/ les booléen
 * 
 * 	Si tu as déjà utilisé les conditions tu dois savoir que
 *
 *	TRUE et FALSE, ne sont que des define de 1 et de 0
 * 	TRUE = 1
 * 	FALSE = 0
 *
 * 	Mais en vrai toute valeur différente de 0 vaut TRUE
 *
 * 2/ Gestion des conditions
 * 	Les conditions sont lu dans l'ordre par le programme,
 *	Il faut savoir que le C est intéligent, il ne va pas s'embeter à calculer des choses inutiles
 * 
 * 	ça implique des chose:
 * 	(Tout ce que je vais dire marche avec tout les types de conditions, je vais utiliser des if pour des raisons de simplicité...)
 *
 * 	si on a:
 * 		if (A && B)
 * 
 * 	Le programme va tester A
 * 	et SSI A est TRUE alors on test B
 * 	Sinon on ne test même pas B 
 *	(puisque la conditions sera fausse, dans ce cas là, peut importe la valeur de B)
 *
 * 
 * 	On a un équivalent avec:
 * 		if (A || B)
 *
 * 	Le programme va tester A
 * 	Si A est TRUE il s'arrete
 * 	et sinon il test B 
 * 	(puisque la condition est respectée peut importe la valeur de B)
 *
 * 3/ Les Affectations
 * 	Une affectation "renvoit" une valeur.
 * 	La valeur de ce qui a été affecté.
 * 
 * 	Par ex:
 * 	(a = 1) donne TRUE
 * 	(a = 0) donne FALSE
 * 	(a = 50999) donne TRUE
 * 	(a = -54) donne TRUE
 *
 * 4/ La table ASCII
 * 	La table ASCII, c'est un peu la pierre de rosette du code.
 * 	C'est ce qui nous permet, nous, de connaitre la valeur numérique de chaque charactère. (du moins les basiques)
 *	grace à ça on sait que 48 = '0', 73 = 'I', 121 = 'y', que 42 = '*'
 *	Le seul caractère qui vaut 0, c'est le '\0'.
 *	En pratique il sert de fin de chaine de caractères ou de fin de fichier. C'est un peu le point final des fichier informatiques, tu vas vite t'en rendre compte de toute manière.
 *
 * 	On sait donc que la valeur ASCII des charactères '0' '1' '2' ... '8' et '9' est toujours différente de 0.
 *
 *
 *
 *
 * "Mais dis moi Jamie, pourquoi tu me racontes ta vie ? Moi je veux raccourcir mon programme !"
 * Si tu as pas compris où je voulais en venir, je vais m'expliquer enfin
 *
 * imaginons nos lignes:
 *
 * int j;
 *
 * j = 0;
 * if (A)
 * {
 *	j = '1';
 *	(reste du code à executer si A est vrai)
 * }
 * 
 *
 * On sait que que j = '1' renvoit '1' (règle 3) donc renvoit TRUE (règle 1 et 4).
 * On aussi que cette ligne ne sera executer que si A est TRUE, et magie grace à la règle 2
 *
 * if (A && (j = '1'))
 * {
 * 	(reste du code à executer si A est vrai)
 * }
 *
 * On met l'affecation entre parenthèse pour que le compilateur comprenne que c'est bien l'affectation (j = '1') qu'il doit tester en tant que booléen.
 * Tadam ! on gagne une ligne.
 *
 */

void 	ft_print_comb2(void)
{
	char unite1;
	char dizaine1;
	char unite2;
	char dizaine2;

	dizaine1 = '0';
	unite1 = '0';
	dizaine2 = '0';
	unite2 = '0';
	while(dizaine1 != '9' || unite1 != '8') 
	{
		if (++unite2 > '9')
		{
			unite2 = '0';
			if (++dizaine2 > '9')
			{
				dizaine2 = dizaine1;
				unite2 = unite1 + 2;
				if (++unite1 > '9' && (++dizaine1)) //on affectera + 1 a dizaine1 que si (unite1 > 9) est vrai
				{
					//puisque l'affectation sera toujours vrai on passera à la suite 
					unite1 ='0';
					dizaine2 = dizaine1;
					unite2 = unite1 + 1;
				}
			}
		}
		print_a_comb(dizaine1, unite1, dizaine2, unite2);
	}
}

/*
 * time:
 * real    0m0,136s
 * user    0m0,000s
 * sys     0m0,047s
 *
 */
