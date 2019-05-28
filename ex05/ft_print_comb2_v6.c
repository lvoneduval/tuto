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
 * on fait pareil avec le while
 *
 * Voilà notre condition actuelle:
 *
 * while (a)
 * {
 * 	if (b)
 * 		rien;
 * 	then affiche;
 * }
 *
 * Ce:
 *	if (b)
 *		rien;
 *
 *est ridicule, et prend beaucoup de place (1 ligne pour lui même + 1 ligne vraiment inutile, et potentiellement 2 lignes de crochets).
 *
 * Réfléchissons sur notre programme: 
 *
 * on a une condition d'arret : A
 * on a une conditons que l'on veut toujours tester si A est vrai (pour les affecations et incrémentations): B
 * et on a un affichage que l'on veut toujours faire si A est vrai peut importe B: affiche
 *
 * Testons:
 * while(A && B)
 * 	affiche;
 *
 * on a bien notre condition d'arret: A
 * on a bien notre conditions que l'on teste bien si A est vrai: B
 * Mais si par malheur B n'est pas respecté, ça n'affichera pas ! Nous nous voulons afficher , peut importe B !
 *
 * "Mais oui c'est claire! la congolexicomatisation des lois du marché propres aux congolais je vous prie"
 * on va rendre B toujours vrai
 *
 * 
 * comment ?
 * B (peut-être faux)
 * 1 est toujours vrai
 * donc (B || 1) est toujours vrai peut importe B
 * ainsi on garde bien le teste de B
 * 
 * On obtient donc:
 * while (a && (b || 1))
 * 	affiche;
 *
 * /!\ On ne peut pas faire (1 || b) puisque b ne sera jamais testé dans ce cas là
 *
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
	while((dizaine1 != '9' || unite1 != '8') // condition d'arret (a)
	&& (((++unite2 > '9' && (unite2 = '0')) 
	&& (++dizaine2 > '9' && (dizaine2 = dizaine1) && (unite2 = unite1 + 2))
	&& (++unite1 > '9' && (++dizaine1) && (unite1= '0') && (dizaine2 = dizaine1) && (unite2 = unite1 + 1))) || 1)) // (b || 1)
		print_a_comb(dizaine1, unite1, dizaine2, unite2);
}


/*
 * time:
 * real    0m0,134s
 * user    0m0,000s
 * sys     0m0,015s
*/
