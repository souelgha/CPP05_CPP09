/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:37:55 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/24 11:37:26 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("noname"),_grade(150) {}
Bureaucrat::Bureaucrat(std::string name, unsigned int grade):_name(name), _grade(grade)
{
	if(_grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if(_grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	
}
Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	if(copy._grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if(copy._grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this-> _grade = copy._grade;
}
Bureaucrat& Bureaucrat::operator=(Bureaucrat const &copy)
{
	if(this !=&copy)
	{
		if(copy._grade < HIGHEST)
			throw Bureaucrat::GradeTooHighException();
		if(copy._grade > LOWEST)
			throw Bureaucrat::GradeTooLowException();
		this-> _grade = copy._grade;
	}
	return(*this);
}
Bureaucrat::~Bureaucrat(){}
std::string Bureaucrat::getName() const
{
	return(this->_name);
}
unsigned int Bureaucrat::getGrade() const
{
	return(this->_grade);
}
void Bureaucrat::IncrementGrade() 
{
	this->_grade--;
	if(_grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::DecrementGrade() 
{
	this->_grade++;
	if(_grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "TooHighException";
}
const char*  Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "TooLowException";
}
void Bureaucrat::signForm(Form& paper)
{
	paper.beSigned(*this);

	if(paper.getStatus() == false)
	{
		std::cout << RED << this->_name ;
		std::cout << " couldn't sign " << paper.getName();
		std::cout << " because " << this->_grade << " his too low Grade!" << WHITE << std::endl;
	}
}
std::ostream& operator<<(std::ostream& os, Bureaucrat & buro)
{
	os << buro.getName() << ", bureaucrat grade " << buro.getGrade() << "\n";
	return(os);
}