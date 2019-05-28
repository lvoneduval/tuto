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
// une version en OR du programme raccourcie, je trouvais que le (b || 1) était très moche, du coup j'ai réfléchi dessus :)
/*
 * La logique n'est pas très différente, disons que je suis passé de: 
 * Si on passe à la dizaine suivante -> on fait ça
 * Si on n'est pas résté dans notre dizaine -> on fait ça
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
	while((dizaine1 <= '9' && unite1 <= '8') &&
	(++unite2 <= '9' 
	|| (++dizaine2 <= '9' && (unite2 = '0'))
	|| (++unite1 <= '9' && (dizaine2 = dizaine1) && (unite2 = unite1 + 1))
	|| ((++dizaine1) && (unite1 = '0') && (dizaine2 = dizaine1) && (unite2 = unite1 + 1)))
	)
		print_a_comb(dizaine1, unite1, dizaine2, unite2);
}
