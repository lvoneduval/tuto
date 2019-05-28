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
 * là on va supprimer les lignes de déclaration de variables.
 * on pouvait le faire avant mais je trouvais ça plus facile de continuer avec des variables lisibles.
 * fini la lisibilité
 *
 * assez facil en soit.
 * on va passer de 4 variables à un tableau de variable
 *
 * de:
 *      char unite1;
 *	char dizaine1;
 *	char unite2;
 *	char dizaine2;
 * a:
 * 	char comb[4];
 *
 * 	où dizaine1, unite1, dizaine2, unite2, deviennent respectivement comb[0], comb[1], comb[2], comb[3];
 *
 * pour eviter de changer les variables à la main une par une vim nous propose la commande (substitute) :s tel que
 * :(Range)s/regex_a_chercher/regex_pour_remplacer/(Rules)
 *
 * ex:
 *
 * :s/foo/bar/	Change la première occurence de 'foo' en 'bar' dans la ligne courrante.
 * :s/foo/bar/g	Change toutes les occurences de 'foo' en 'bar' dans la ligne courrante. (g global)
 * :1,5s/foo/bar/g Change toutes les occurences de 'foo' en 'bar' des lignes 1 à 5
 * :%s/foo/bar/g Change toutes les occurences de 'foo' en 'bar' de toutes les ligne (% = toutes les lignes)
 *
 * ici on va faire le changement que dans la fonction ft_print_comb2 du coup de la ligne 61 à 71 (pour moi)
 * :61,71s/dizaine1/comb[0]/g
 * :61,71s/unite1/comb[1]/g
 * :61,71s/dizaine2/comb[2]/g
 * :61,71s/unite2/comb[3]/g
 *
 *
 * Mais ce n'est pas fini.
*/
void 	ft_print_comb2(void)
{
	char comb[4];
 	
	comb[0] = '0';
 	comb[1] = '0';
 	comb[2] = '0';
	comb[3] = '0';
	while((comb[0] != '9' || comb[1] != '8') &&
	((++comb[3] > '9' && (comb[3] = '0')
	&& (++comb[2] > '9' && (comb[2] = comb[0]) && (comb[3] = comb[1] + 2))
	&& (++comb[1] > '9' && (++comb[0]) && (comb[1]= '0') && (comb[2] = comb[0]) && (comb[3] = comb[1] + 1))) || 1))
		print_a_comb(comb[0], comb[1], comb[2], comb[3]);
}

/*
 * time:
 * real    0m0,136s
 * user    0m0,000s
 * sys     0m0,031s
 */
