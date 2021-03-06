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
#ifndef CASPLANNERVORONOIPATHPLANNER_H
#define CASPLANNERVORONOIPATHPLANNER_H
#include <libplayerc++/playerc++.h>
#include <libplayerinterface/player.h>

#include <QDebug>

#include "astar.h"
#include "mapskeleton.h"

namespace CasPlanner
{

/**
Generates a Path using a Map Skeleton Generated by Voronoi Diagram

        @author Tarek Taha <tataha@eng.uts.edu.au>
*/
class VoronoiPathPlanner : public Astar
{
public :
    VoronoiPathPlanner(MapSkeleton &mapSkeleton);
    VoronoiPathPlanner();
    ~VoronoiPathPlanner();
    void freeResources();
    void freePath();
    void printNodeList ();
    void setMapSkeleton(MapSkeleton & mapSkeleton);
    void buildSpace();
    void showConnections();
    void setMap(Map * map_in);
    void saveSearchSpace();
    bool readSpaceFromFile(const char *filename);
    bool saveSpace2File(const char *filename);
    void setStart(Pose start);
    void setEnd(Pose start);
private :
    bool skelInitialize;
};

}

#endif
