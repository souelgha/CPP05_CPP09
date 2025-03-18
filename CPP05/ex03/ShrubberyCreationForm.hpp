/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:25:51 by sonouelg          #+#    #+#             */
/*   Updated: 2024/10/23 17:56:05 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
	#define SHRUBBERYCREATIONFORM_H

#include"AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(const ShrubberyCreationForm & target);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm & target);
		~ShrubberyCreationForm();

		void action() const;
		ShrubberyCreationForm* clone(std::string target) const;
	

};

#endif