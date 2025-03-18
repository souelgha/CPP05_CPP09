/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:52:56 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/24 11:24:47 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
	#define AFORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _status;
		unsigned int const _gradeToSigned;
		unsigned int const _gradeToExecute;
	
	public:
		AForm();
		AForm(std::string name, unsigned int tosigned, unsigned int toexec);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);
		virtual ~AForm();

		std::string getName() const;
		unsigned int getGradToSign() const;
		unsigned int getGradToExec() const;
		bool getStatus() const;

		void beSigned(Bureaucrat& buro);		
		void execute(Bureaucrat const & executor) const;
		virtual void action() const = 0;
		virtual AForm* clone(std::string target) const = 0;

		class GradeTooLowException: public std::exception
		{	
			public:
				const char *what() const throw();
		};
		class GradeTooHighException: public std::exception
		{	
			public:
				const char *what() const throw();
		};
};
std::ostream& operator<<(std::ostream& os, AForm & paper);

#endif