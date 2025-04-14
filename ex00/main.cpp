/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:05:07 by zchtaibi          #+#    #+#             */
/*   Updated: 2025/04/14 19:21:26 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int i;

    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    i = 0;
    while (++i < ac)
    {
        std::string str;
        size_t      j;

        str = av[i];
        j = -1;
        while (++j < str.length())
            str[j] = std::toupper(str[j]);
        std::cout << str;
        if (i < ac - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}