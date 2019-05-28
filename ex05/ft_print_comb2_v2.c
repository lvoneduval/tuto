void ft_putchar(char c);

//La fonction d'affichage ne va pas changer jusqu'a la fin.
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
 *
 * L'incrémentation dans les conditions.
 * De ce que j'ai vu, tu connais cette technique pas besoin de l'expliquer.
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
		if (++unite2 > '9') // ici
		{
			unite2 = '0';
			if (++dizaine2 > '9') // ici
			{
				dizaine2 = dizaine1;
				unite2 = unite1 + 2; // unite1 incrémentait avant cette affectation, on fait donc en sorte de ne pas oublié un +1 ici.
				if (++unite1 > '9') // et ici
				{
					dizaine1++;
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
 * real    0m0,142s
 * user    0m0,000s
 * sys     0m0,047s
 */
