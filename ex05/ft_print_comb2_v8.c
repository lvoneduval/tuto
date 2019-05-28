void ft_putchar(char c);
/*
* On va s'occuper de la fonction d'affichage maintenant.
* on va la remettre dans la fonction principale
* et puisque nous avons:
*
*			if (comb[0] == '9' && comb[1] == '8')
*				return ;
*
*nous n'avons plus besoin de la condition dans la boucle.
*nous aurons donc une boucle infinie volontaire qui s'arrete lorsque la condition n'est pas réspectée.
* 
* nous allons choisir,ici un "break;" pour casser la boucle au lieu d'un return. C'est une simple question de gout, j'aime quand mes fonctions vont jusqu'aux bout.
* Ce n'est pas toujours judicieux, parfois même, pas du tout.
* 
* On pourrait réduire encore les lignes, avec certains subterifuges, mais
* ça rendrait le code vraiment illisible même pour un initié, et ça influencerait négativement la performence de l'algorithme.
* Mais ...
*/
void 	ft_print_comb2(void)
{
	char comb[4];
	
	comb[0] = '0';
 	comb[1] = '0';
 	comb[2] = '0';
	comb[3] = '0';
	while((++comb[3] > '9' && (comb[3] = '0')
	&& (++comb[2] > '9' && (comb[2] = comb[0]) && (comb[3] = comb[1] + 2))
	&& (++comb[1] > '9' && (++comb[0]) && (comb[1]= '0') && (comb[2] = comb[0]) && (comb[3] = comb[1] + 1))) || 1)
	{
		ft_putchar(comb[0]);
		ft_putchar(comb[1]);
		ft_putchar(' ');
		ft_putchar(comb[2]);
		ft_putchar(comb[3]);
		if (comb[0] == '9' && comb[1] == '8')
			break ;
		ft_putchar(',');
		ft_putchar(' ');
	}
}

/*
 * time:
 * real    0m0,133s
 * user    0m0,000s
 * sys     0m0,031s
*/
