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
* grâce à ce qu'on a vue précédement on peut mettre toutes les affecations dans les ifs.
*
* Tu le sais sûrrement, mais on peut remplacer:
*
* if (a)
* {
*	une_unique_instruction;
* }
*
* par :
*
* if (a)
* 	une_unique_instruction;
*
* On supprime de ce fait, tout les crochets
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
		if (++unite2 > '9' && (unite2 = '0'))
			if (++dizaine2 > '9' && (dizaine2 = dizaine1) && (unite2 = unite1 + 2))
				if (++unite1 > '9' && (++dizaine1) && (unite1= '0') && (dizaine2 = dizaine1) && (unite2 = unite1 + 1))
					(void)1; // instruction vide pour que la combilation marche
		print_a_comb(dizaine1, unite1, dizaine2, unite2);
	}
}

/* time:
 * real    0m0,130s
 * user    0m0,000s
 * sys     0m0,031s
 *
 * Le temps d'execution à l'air de baisser, mais ne tire pas de conclusions, je ne fais que 10 testes, ce n'est pas forcément représentatif.
 */ 
