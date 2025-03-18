/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:27:01 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/23 18:01:13 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
	#define ROBOTOMYREQUESTFORM_H

	
#include"AForm.hpp"
#include "stdlib.h"

class RobotomyRequestForm: public AForm
{		
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(const RobotomyRequestForm & target);
		RobotomyRequestForm& operator=(const RobotomyRequestForm & target);
		~RobotomyRequestForm();

		void action() const;
		RobotomyRequestForm* clone(std::string target) const;

};
#endif