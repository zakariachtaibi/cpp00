/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:22:29 by zchtaibi          #+#    #+#             */
/*   Updated: 2025/04/14 21:25:57 by zchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Point3d
{
    private:
        int m_x;
        int m_y;
        int m_z;
    public:
        void setValues(int x, int y, int z)
        {
            m_x = x;
            m_y = y;
            m_z = z;
        }
        void print()
        {
            std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">";
        }
};

int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    return 0;
}