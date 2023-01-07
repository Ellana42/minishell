/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaploun <mkaploun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:54:43 by mkaploun          #+#    #+#             */
/*   Updated: 2023/01/07 11:56:15 by mkaploun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "../tokenizer/tokenizer.h"
# include "../../glob/glob.h"

int	tokenize_noquote(t_tokenizer *tokenizer);
int	tokenize_noquotev(t_tokenizer *tokenizer);
int	tokenize_quote(t_tokenizer *tokenizer);
int	tokenize_quotev(t_tokenizer *tokenizer);
int	tokenize_single_quote(t_tokenizer *tokenizer);
int	tokenize(t_tokenizer *tokenizer);
int	tokenize_noquote_dollar(t_tokenizer *tokenizer);
int	tokenize_noquote_pipe(t_tokenizer *tokenizer);
int	tokenize_noquote_quote(t_tokenizer *tokenizer);
int	tokenize_noquote_squote(t_tokenizer *tokenizer);
int	tokenize_noquote_space(t_tokenizer *tokenizer);
int	tokenize_noquote_out(t_tokenizer *tokenizer);
int	tokenize_noquote_in(t_tokenizer *tokenizer);

#endif
