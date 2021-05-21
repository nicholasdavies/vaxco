//
// PROCESS
//

#ifndef PROCESS_SPEC_H
#define PROCESS_SPEC_H

#include "helper.h"

enum SourceID
{
    srcS = 1000000,
    srcE,
    srcEv,
    srcEp,
    srcEvp,
    srcEa,
    srcEva,
    srcIp,
    srcIs,
    srcIa,
    srcI,
    srcCasesReported
};

const map<string,SourceID> processSourceMap = {
    {"S", srcS},
    {"E", srcE},
    {"Ev", srcEv},
    {"Ev_Ip", srcEvp},
    {"Ev_Ia", srcEva},
    {"E_Ip", srcEp},
    {"E_Ia", srcEa},
    {"Ip",srcIp},
    {"Is",srcIs},
    {"Ia",srcIa},
    {"I",srcI},
    {"cases_reported", srcCasesReported}
};

const unsigned int Null = 999999;
class Discrete;

struct ProcessSpec
{
    unsigned int source_id; // identifier for the compartment which, upon exiting, individuals enter this process
    string source_name;     // name of the above
    string type;            // ignored for now - multinomial or dirichlet multinomial

    vector<string> names;       // names of sub-processes
    vector<unsigned int> ids;   // identifiers of sub-process compartments
    vector<string> report;      // reporting mode of sub-processes: empty, "i", "o", "p", or a combination of these
    vector<vector<double>> prob;// probability by group of entering each sub-process from the source above; indexed by group then by subprocess
    vector<Discrete> delays;    // delays for each sub-process

    vector<unsigned int> p_cols;
    vector<unsigned int> p_ids;
    vector<unsigned int> i_cols;
    vector<unsigned int> i_ids;
    vector<unsigned int> o_cols;
    vector<unsigned int> o_ids;     // prevalence, incidence, and outcidence data columns and sub-process identifiers for this process
};

#endif