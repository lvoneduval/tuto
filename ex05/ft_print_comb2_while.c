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

void 	ft_print_comb2(void)
{
	char unite1;
	char dizaine1;
	char unite2;
	char dizaine2;

	dizaine1 = '0';
	unite1 = '0';
	dizaine2 = '0';
	unite2 = '1';	
	while(dizaine1 <= '9')
	{
		while(unite1 <= '9')
		{
			while(dizaine2 <= '9')
			{
				while(unite2 <= '9')
				{
					print_a_comb(dizaine1, unite1, dizaine2, unite2);
					unite2++;
				}
				dizaine2++;
				unite2 = '0';
			}
			unite1++;
			unite2 = unite1 + 1;
			dizaine2 = dizaine1;
		}
		dizaine1++;
		unite1 = '0';
		dizaine2 = dizaine1;
		unite2 = unite1 + 1;
	}
}
