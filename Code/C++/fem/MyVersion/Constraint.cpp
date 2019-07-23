#include "Constraint.h"

Constraint::Constraint(int id, int node, int ctr1, int ctr2, int ctr3)
  :tag(id), nodeTag(node)
{
  constraint[0] = 0.;
  constraint[1] = 0.;
  constraint[2] = 0.;
}

int
Constraint::GetTag(void) {
  return tag;
}

int
Constraint::GetNodeTag(void) {
  return nodeTag;
}

const int *
Constraint::GetConstraint() {
  return constraint;
}

void 
Constraint::Print(std::ostream &s){
  s << " Constraint: " << tag;
  s << " Node: " << nodeTag;
  s << " Constraints: " << constraint[0] << " " << constraint[1] << " " << constraint[2] << "\n";
}

