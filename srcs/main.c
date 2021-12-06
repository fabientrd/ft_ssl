#include "../incs/ft_ssl.h"

void	init_env(t_env *env){
	env->cmd = 0;
	env->p = 0;
	env->q = 0;
	env->r = 0;
	env->s = 0;
	env->bytes = 0;
	env->begin = 0;
}

int	check_flags(int ac, char **av, t_env *env){
	// int i;
	(void)env;
	// i = 2;
	for (int i = 2; i < ac; i++){
		if (av[i][0] != '-'){
			env->begin = i;
			break ;
		}
		if (av[i][1] == 'p' || av[i][1] == 'q' || av[i][1] == 'r' || av[i][1] == 's'){
			if (av[i][1] == 'p') env->p = 1;
			else if (av[i][1] == 'q') env->q = 1;
			else if (av[i][1] == 'r') env->r = 1;
			else env->s = 1;
		}
		else{
			printf("ft_ssl: Error: '%s' is an invalid flag.\n", av[i]);
			return (1);
		}
	}
	return (0);
}

int check_cmd(char **av, t_env *env){
	if (ft_strncmp(av[1], "md5", 3) && ft_strncmp(av[1], "sha256", 5)){
		printf("ft_ssl: Error: '%s' is an invalid command.\n", av[1]);
		return (1);
	}
	else
		env->cmd = !ft_strncmp(av[1], "md5", 3) ? env->cmd : 1;
	return (0);
}

int		main(int ac, char **av){
	t_env	env;

	if (ac == 1){
		printf("usage: ft_ssl command [flags] [file/string]\n");
		return EXIT_FAILURE;
	}
	init_env(&env);
	// GERER LE READ POUR PRENDRE UN echo "..." | ./ft_ssl [command] [flags] [file/string] SANS ATTENDRE UNE ENTREE QUAND ON FAIT JUSTE ./ft_ssl [command] [flags] [file/string]
	// if ((env.bytes = read(STDIN_FILENO, env.buf, 2048)) > 0)
		// env.buf[env.bytes - 1] = '\0';
	// printf("Le echo envoie %s\n", env.buf);
	if (check_cmd(av, &env)){
		printf("\nCommands:\nmd5\nsha256\n\nFlags:\n-p -q -r -s\n");
		return (EXIT_FAILURE);
	}
	if (check_flags(ac, av, &env)){
		printf("\nCommands:\nmd5\nsha256\n\nFlags:\n-p -q -r -s\n");
		return (EXIT_FAILURE);
	}
	env.cmd == 0 ? ft_md5(av, &env) : ft_sha256(av, &env);
	return (0);
}