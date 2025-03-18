/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:26:25 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/23 17:34:36 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("unknown", 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(std::string const target):AForm(target, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & target): AForm(target){}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm & target)
{
	if(this != &target)
		AForm::operator=(target);
	return(*this);
}
RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::action()const
{
	srand(time(0));
	std::cout << "...Drilling noises..." << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->getName() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getName() << " has failed to be robotomized." << std::endl;
}