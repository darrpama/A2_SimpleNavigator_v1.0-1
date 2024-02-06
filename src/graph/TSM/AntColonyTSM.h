#ifndef _ANTCOLONYTSM_H_
#define _ANTCOLONYTSM_H_

#include "TravelingSalesman.h"

namespace s21 {
    class AntColonyTSM : public TravelingSalesman {
       public:
        TravelingSalesman::TsmResult solve(const Graph& graph) override;
    };
} // namespace s21

#endif  // _ANTCOLONYTSM_H_
