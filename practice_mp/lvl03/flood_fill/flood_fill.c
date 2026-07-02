/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_fill.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: andjajas <andjajas@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/07/02 19:14:08 by andjajas      #+#    #+#                 */
/*   Updated: 2026/07/02 19:14:09 by andjajas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void fill(char**tab, t_point size, t_point curr, char to_fill) {
	if (curr.x < 0 || curr.x >= size.x || curr.y < 0 || curr.y >= size.y || tab[curr.y][curr.x] != to_fill)
		return ;
	tab[curr.y][curr.x] = 'F';
	fill(tab, size, (t_point){curr.x, curr.y+1}, to_fill);
	fill(tab, size, (t_point){curr.x, curr.y-1}, to_fill);
	fill(tab, size, (t_point){curr.x+1, curr.y}, to_fill);
	fill(tab, size, (t_point){curr.x-1, curr.y}, to_fill);
}

void  flood_fill(char **tab, t_point size, t_point begin) {
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
