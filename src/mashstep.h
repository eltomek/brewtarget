/*
 * mashstep.h is part of Brewtarget, and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009.
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MASHSTEP_H
#define _MASHSTEP_H
#include <string>
#include <exception>
#include "xmlnode.h"
#include "observable.h"
#include <QDomNode>
#include "BeerXMLElement.h"

class MashStep;
class MashStepException;

class MashStep : public Observable, public BeerXMLElement
{
public:

   MashStep();
   MashStep(const XmlNode *node);
   MashStep( const QDomNode& mashStepNode );

   friend bool operator<(MashStep &m1, MashStep &m2);
   friend bool operator==(MashStep &m1, MashStep &m2);

   virtual void toXml(QDomDocument& doc, QDomNode& parent); // From BeerXMLElement
   //std::string toXml();
   
   void setName( const std::string &var );
   void setType( const std::string &var );
   void setInfuseAmount_l( double var );
   void setStepTemp_c( double var );
   void setStepTime_min( double var );
   void setRampTime_min( double var );
   void setEndTemp_c( double var );

   std::string getName() const;
   std::string getType() const;
   double getInfuseAmount_l() const;
   double getStepTemp_c() const;
   double getStepTime_min() const;
   double getRampTime_min() const;
   double getEndTemp_c() const;

   // My extensions
   void setInfuseTemp_c( double var );
   double getInfuseTemp_c() const;
   void setDecoctionAmount_l( double var );
   double getDecoctionAmount_l() const;
   // ===

private:

   std::string name;
   static const int version = 1;
   std::string type;
   double infuseAmount_l;
   double stepTemp_c;
   double stepTime_min;
   double rampTime_min;
   double endTemp_c;

   // My extensions
   double infuseTemp_c;
   double decoctionAmount_l;
   // ===

   bool isValidType( const std::string &str ) const;
   void setDefaults();
};

class MashStepException : public std::exception
{
public:

   virtual const char* what() const throw()
   {
      return std::string("BeerXML MASH_STEP error: " + _err + "\n").c_str();
   }

   MashStepException( std::string message )
   {
      _err = message;
   }

   ~MashStepException() throw() {}

private:

   std::string _err;
};

struct MashStep_ptr_cmp
{
   bool operator()( MashStep* lhs, MashStep* rhs)
   {
      return *lhs < *rhs;
   }
};

struct MashStep_ptr_equals
{
   bool operator()( MashStep* lhs, MashStep* rhs )
   {
      return *lhs == *rhs;
   }
};

#endif //_MASHSTEP_H