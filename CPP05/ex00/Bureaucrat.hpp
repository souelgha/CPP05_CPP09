/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:04:58 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/11 13:31:14 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
	#define BUREAUCRAT_H

#include <iostream>
#include <exception>

#define HIGHEST 1
#define LOWEST 150

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"


class Bureaucrat
{
	private:
		std::string const _name;
		unsigned int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat& operator=(Bureaucrat const& copy);		
		~Bureaucrat();

		void IncrementGrade();
		void DecrementGrade();

		std::string getName() const;
		unsigned int getGrade() const;
		
		class GradeTooHighException : public std::exception 
		{
            public:
               const char *what() const throw();
		};
		class GradeTooLowException : public std::exception 
		{
    		public:
       			const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os,Bureaucrat & buro);

#endif