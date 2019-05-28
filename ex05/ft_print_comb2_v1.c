void ft_putchar(char c);


/*
 *
 *Petit tuto de Raccourcicement de fonctions,
 *On va partir de ma version du printcomb2, que je trouve plus logique dans l'execution
 *Tout est commenté d'une façon interdite par la norme.
 *Toutes les manipulations que j'ai fait sont autorisées par la norme, mais certaines d'entre elles, je trouve, rendent le code illisible.
 *Ce qui rend la maintenance du code impossible. En cas de problème ou de refonte, l'intégralité du code devra être reécrit
 * à n'utiliser que dans 2 cas majeurs:
 * 	1/ La flemme, c'est pas important de toute façon osef.
 * 	2/ Impossiblité de split une fonction longue. (Meme si en vrai y a toujours moyen)
 *
 * Pendant toute la durée du raccourcicement je vais mesurer le temps d'execution du code afin de voir comment agit les modifications sur les performences.
 * Pour ça je vais utiliser la commande "time" de cette manière:
 * 	time nomdemonprogramme.
 *
 *Je vais réitérer cette opération 10 fois et en faire une moyenne.
 *Le but principale c'est de voir si nos changement n'affectent pas drastiquement les performence (genre si on perd pas 1 sec d'exectution)
 *J'afficherai la moyenne en commentaire, tout à la fin du programme.
 */ 

// Pour plus facilement travailler sur le code, on va séparer la fonction en 2 fonctions, celle d'affichage,
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

// et celle de calcule.
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
	while(dizaine1 != '9' || unite1 != '8') //tant qu'on affiche pas le dernier.
	{
		unite2++;//on augmente le nombre2 de 1
		if (unite2 > '9') // si on a parcouru toute la dizaine du nombre2
		{
			dizaine2++; //on change de dizaine
			unite2 = '0';
			if (dizaine2 > '9') // si on a fait toute les combinaisons possible de nombre2 avec nombre1, on passe au nombre1 suivant
			{
				unite1++;
				dizaine2 = dizaine1;
				unite2 = unite1 + 1;
				if (unite1 > '9') //on gère les dizaines du nombre1
				{
					dizaine1++;
					unite1 ='0';
					dizaine2 = dizaine1;
					unite2 = unite1 + 1;
				}
			}
		}
		print_a_comb(dizaine1, unite1, dizaine2, unite2); //on affiche
	}
}

/* time: 
 * real    0m0,173s
 * user    0m0,015s
 * sys     0m0,031s
*/
