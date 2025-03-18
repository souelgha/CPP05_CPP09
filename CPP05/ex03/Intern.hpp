/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:33:22 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/24 12:07:56 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
	#define INTERN_H

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	private:
		AForm *form[3];

	public:
		Intern();
		~Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);

		AForm* makeForm(std::string FormName, std::string target);
		
		class FormDoesntExist: public std::exception
		{
			public:
				const char *what() const throw();
		};

};

#endif