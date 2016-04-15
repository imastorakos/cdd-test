#ifndef CDD-TESTAPP_H
#define CDD-TESTAPP_H

#include "MooseApp.h"

class Cdd-TestApp;

template<>
InputParameters validParams<Cdd-TestApp>();

class Cdd-TestApp : public MooseApp
{
public:
  Cdd-TestApp(InputParameters parameters);
  virtual ~Cdd-TestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* CDD-TESTAPP_H */
