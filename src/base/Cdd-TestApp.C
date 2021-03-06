#include "Cdd-TestApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<Cdd-TestApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

Cdd-TestApp::Cdd-TestApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  Cdd-TestApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  Cdd-TestApp::associateSyntax(_syntax, _action_factory);
}

Cdd-TestApp::~Cdd-TestApp()
{
}

// External entry point for dynamic application loading
extern "C" void Cdd-TestApp__registerApps() { Cdd-TestApp::registerApps(); }
void
Cdd-TestApp::registerApps()
{
  registerApp(Cdd-TestApp);
}

// External entry point for dynamic object registration
extern "C" void Cdd-TestApp__registerObjects(Factory & factory) { Cdd-TestApp::registerObjects(factory); }
void
Cdd-TestApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void Cdd-TestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { Cdd-TestApp::associateSyntax(syntax, action_factory); }
void
Cdd-TestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
