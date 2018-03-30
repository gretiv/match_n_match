
int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_rmatch(char *s1, char *s2, int i, int j)
{
	if (i == ft_strlen(s1) && j == ft_strlen(s2))
		return (1);
	if (ft_strlen(s1) < i && ft_strlen(s2) < j)
		return (0);
	if (s1[i] == s2[j] && s2[j] != '*')
		return (ft_rmatch(s1, s2, i + 1, j + 1));
	if (s2[j] == '*' && s1[i] == 0)
		return (ft_rmatch(s1, s2, i, j + 1));
	if (s2[j] == '*' && s1[i] != 0)
		return (ft_rmatch(s1, s2, i + 1, j) || ft_rmatch(s1, s2, i, j + 1));
	return (0);
}

int	match(char *s1, char *s2)
{
	return (ft_rmatch(s1, s2, 0, 0));
}
