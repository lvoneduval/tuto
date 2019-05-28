void ft_putchar(char c);
/*
*  Mais si vraiment t'as besoin de ligne, un truc que ne change pas drastiquement la performence mais qui raccourcie le code:
*  notre bonne vieille affectation dans une condition.
*/
void 	ft_print_comb2(void)
{
	char comb[4];
	
	if ((comb[0] = '0') && (comb[1] = '0')&& (comb[2] = '0') && (comb[3] = '0')) // si les affectations sont respectées (tout le temps)
		while((++comb[3] > '9' && (comb[3] = '0')
			&& (++comb[2] > '9' && (comb[2] = comb[0]) && (comb[3] = comb[1] + 2))
			&& (++comb[1] > '9' && (++comb[0]) && (comb[1]= '0') 
			&& (comb[2] = comb[0]) && (comb[3] = comb[1] + 1))) || 1)
			{
				ft_putchar(comb[0]); //Ici on pourrait faire en sorte de rajouter ' ' dans le tableau de comb (au milieu)
				ft_putchar(comb[1]); //Puis de faire un:
				ft_putchar(' ');     // while (++i < 5)
				ft_putchar(comb[2]); // 	ft_putchar(comb[i]);
				ft_putchar(comb[3]); // mais ça ne nous ferrait gagner qu'une ligne pour multiplier par 5 nos conditions testées (5 tests de plus par tour de boucle)
				if (comb[0] == '9' && comb[1] == '8')
					break ;
				ft_putchar(',');
				ft_putchar(' ');
			}
}

/*
 * time:
 * real    0m0,136s
 * user    0m0,000s
 * sys     0m0,015s
 */
