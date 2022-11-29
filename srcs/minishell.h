
typedef struct s_command{
	char *command;
	char **args;
	char **out; // pour > 
	char **out_a; // pour >>
	char **in; // pour < 
	char **in_a; // pour <<
	int	piped; // est-ce que tu passes à la suivante
} t_command;
