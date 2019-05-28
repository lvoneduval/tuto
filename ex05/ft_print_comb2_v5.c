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
* if (a)
* 	 if (b)
* 		 if (c)
* 			then d;
*/ 
// Equivaut à:

/*
* if (a && b && c)
* 	then d;
*
*/ 
//On fait la même chose ici

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
		if ((++unite2 > '9' && (unite2 = '0')) //je les place sur des lignes différentes pour des raisons de lisibilité, mais bon, ce n'est pas necessaire.
		&& (++dizaine2 > '9' && (dizaine2 = dizaine1) && (unite2 = unite1 + 2))
		&& (++unite1 > '9' && (++dizaine1) && (unite1= '0') && (dizaine2 = dizaine1) && (unite2 = unite1 + 1)))
					(void)1; // instruction vide pour que la combilation marche
		print_a_comb(dizaine1, unite1, dizaine2, unite2);
	}
}


/* time
 * real    0m0,135s
 * user    0m0,000s
 * sys     0m0,015s
 */
