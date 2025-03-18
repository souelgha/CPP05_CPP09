/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:51:35 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/23 18:01:13 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("unknown", 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(std::string const target):AForm(target, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & target): AForm(target){}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm & target)
{
	if(this != &target)
		AForm::operator=(target);
	return(*this);
}
PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::action()const
{
	std::cout <<this->getName() << " has been pardoned by Zaphod Beeblebrox. Congratulations !" << std::endl;
}
PresidentialPardonForm* PresidentialPardonForm::clone(std::string target) const 
{
	return(new PresidentialPardonForm(target));
}