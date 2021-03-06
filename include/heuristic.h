/***************************************************************************
 *   Copyright (C) 2006 - 2007 by                                          *
 *      Tarek Taha, CAS-UTS  <tataha@tarektaha.com>                        *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Steet, Fifth Floor, Boston, MA  02111-1307, USA.          *
 ***************************************************************************/
#ifndef HEURISTICT_H_
#define HEURISTICT_H_

#include <QString>
#include <QHash>
#include "ssppexception.h"
#include "node.h"
#include <component_test/occlusion_culling_gpu.h>
#include <component_test/occlusion_culling.h>

using namespace std;

namespace SSPP
{

class Heuristic
{
public:
    virtual ~Heuristic(){}
    virtual double gCost(Node *)=0;
    virtual double hCost(Node *,Node * )=0;
    virtual double hCost(Node *)=0;
//    double hCovCost(Node *n);
    static Heuristic * factory(QString type, bool debug) throw(SSPPException);
};

class DistanceHeuristic : public Heuristic
{
public:
    bool H_debug;
    DistanceHeuristic(bool d){H_debug=d;}
    friend class Heuristic;
public:
    double gCost(Node *n);
    double hCost(Node *n, Node * end);
    double hCost(Node *n){}
    ~DistanceHeuristic(){}
};

class SurfaceCoverageHeuristic : public Heuristic
{
public:
    bool H_debug;
    SurfaceCoverageHeuristic(bool d){H_debug=d;}
    friend class Heuristic;
public:
    double gCost(Node *n);
    double hCost(Node *n, Node * end){}
    double hCost(Node *n);
    ~SurfaceCoverageHeuristic(){}
};

class SCwithOrientationHeuristic : public Heuristic
{
public:
    bool H_debug;
    SCwithOrientationHeuristic(bool d){H_debug=d;}
    friend class Heuristic;
public:
    double gCost(Node *n);
    double hCost(Node *n, Node * end){}
    double hCost(Node *n);
    ~SCwithOrientationHeuristic(){}
};

}
#endif /*HEURISTICT_H_*/
