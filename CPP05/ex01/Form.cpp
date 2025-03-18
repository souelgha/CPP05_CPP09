/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:52:59 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/28 16:10:03 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():
	_name("unknown_Form"), _status(false),_gradeToSigned(LOWEST), _gradeToExecute(LOWEST) 
	{
		if(this->_gradeToSigned < HIGHEST || this->_gradeToExecute < HIGHEST)
			throw GradeTooHighException();
		if(this->_gradeToSigned > LOWEST || this->_gradeToExecute > LOWEST)
			throw GradeTooLowException();
	}
Form::Form(std::string name, unsigned int tosigned, unsigned int toexec):
	_name(name), _status(false),_gradeToSigned(tosigned), _gradeToExecute(toexec)
	{
		if(this->_gradeToSigned < HIGHEST || this->_gradeToExecute < HIGHEST)
			throw GradeTooHighException();
		if(this->_gradeToSigned > LOWEST || this->_gradeToExecute > LOWEST)
			throw GradeTooLowException();		
	}
Form::~Form(){}
Form::Form( Form const& copy):
	_name(copy._name), _status(false),_gradeToSigned(copy._gradeToSigned), _gradeToExecute(copy._gradeToExecute)
{
		*this=copy;
}
Form& Form::operator=(const Form& copy)
{
	(void)copy;
	return(*this);
}

std::string Form::getName() const
{
	return(this->_name);
}
bool Form::getStatus() const
{
	return(this->_status);
}
unsigned int Form::getGradToExec() const
{
	return(this->_gradeToExecute);
}
unsigned int Form::getGradToSign() const
{
	return(this->_gradeToSigned);
}

std::ostream& operator<<(std::ostream& os, Form & infos)
{
	os << infos.getName() << " Form needs grade " 
	<< infos.getGradToSign() << " to sign and grade "
	<< infos.getGradToExec() << " to execute." << "\n";
	return(os);
}
const char* Form::GradeTooHighException::what() const throw()
{
	return("Grade Too High !");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade Too Low ! ");
}
void Form::beSigned(Bureaucrat& buro)
{
	if(this->_status == true)
	{
		std::cout << this->_name <<" Form is already signed. " << std::endl;
		return;
	}
	try 
	{
		if(_gradeToSigned >= buro.getGrade())
		{
			this->_status = true;
			std::cout << buro.getName() ;
			std::cout << " signed " << this->_name << std::endl;
		}
		else 
			throw Form::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr <<RED << buro.getGrade()<<" is " << e.what() << WHITE<< std::endl;
	}
}