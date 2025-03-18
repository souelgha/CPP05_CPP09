/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:52:59 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/24 11:25:56 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():
	_name("unknown_AForm"), _status(false),_gradeToSigned(LOWEST), _gradeToExecute(LOWEST) 
	{
		if(this->_gradeToSigned < HIGHEST || this->_gradeToExecute < HIGHEST)
			throw GradeTooHighException();
		if(this->_gradeToSigned > LOWEST || this->_gradeToExecute > LOWEST)
			throw GradeTooLowException();
	}
AForm::AForm(std::string name, unsigned int tosigned, unsigned int toexec):
	_name(name), _status(false),_gradeToSigned(tosigned), _gradeToExecute(toexec)
	{
		if(this->_gradeToSigned < HIGHEST || this->_gradeToExecute < HIGHEST)
			throw GradeTooHighException();
		if(this->_gradeToSigned > LOWEST || this->_gradeToExecute > LOWEST)
			throw GradeTooLowException();
	}
AForm::~AForm(){}
AForm::AForm(const AForm& copy):
	_name(copy._name), _status(false),_gradeToSigned(copy._gradeToSigned), _gradeToExecute(copy._gradeToExecute)
{
		*this=copy;
}
AForm& AForm::operator=(const AForm& copy)
{
	(void)copy;
	return(*this);
}

std::string AForm::getName() const
{
	return(this->_name);
}
bool AForm::getStatus() const
{
	return(this->_status);
}
unsigned int AForm::getGradToExec() const
{
	return(this->_gradeToExecute);
}
unsigned int AForm::getGradToSign() const
{
	return(this->_gradeToSigned);
}

std::ostream& operator<<(std::ostream& os, AForm & infos)
{
	os << infos.getName() << " Form needs grade " 
	<< infos.getGradToSign() << " to sign and grade "
	<< infos.getGradToExec() << " to execute." << "\n";
	return(os);
}
const char* AForm::GradeTooHighException::what() const throw()
{
	return("Grade Too High !");
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return("Grade Too Low ! ");
}
void AForm::beSigned(Bureaucrat& buro)
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
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr <<RED << e.what() << WHITE<< std::endl;
	}
}
void AForm::execute(Bureaucrat const & executor)const
{
	if(this->_status == true)
	{
		try
		{
			if(_gradeToExecute >= executor.getGrade())
			{
				std::cout << executor.getName() ;
				std::cout << " executed " << this->_name << std::endl;
				action();		
			}
			else				
				throw AForm::GradeTooLowException();
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << executor.getName();
			std::cerr << " can't execute " << this->_name;
			std::cerr << " because " <<  e.what() << WHITE<< std::endl;
		}
	}
	else
		std::cout << this->_name <<" Form is not yet signed! Sign it before !" << std::endl;

}
