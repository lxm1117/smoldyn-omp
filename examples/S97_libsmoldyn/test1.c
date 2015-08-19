//#include <libsmoldyn.h>
#include "/usr/local/include/libsmoldyn.h"

/**** Compiling and linking, for Macs ****
 
Compile source code to object code with either of:
g++ -Wall -O0 -g -c test1.c
gcc -Wall -O0 -g -c test1.c

Static link, if Libsmoldyn was compiled with OpenGL:
(gcc cannot be used for linking because libsmoldyn is in C++ and is a static library)
g++ test1.o -L/usr/local/lib -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -framework GLUT -framework OpenGL -framework Cocoa -L/System/Library/Frameworks/OpenGL.framework/Libraries -o test1 -lsmoldyn_static -ltiff
 
Dynamic link, if Libsmoldyn was compiled with OpenGL, with either of:
gcc test1.o -L/usr/local/lib -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -framework GLUT -framework OpenGL -framework Cocoa -L/System/Library/Frameworks/OpenGL.framework/Libraries -o test1 -lsmoldyn_shared -ltiff
g++ test1.o -L/usr/local/lib -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -framework GLUT -framework OpenGL -framework Cocoa -L/System/Library/Frameworks/OpenGL.framework/Libraries -o test1 -lsmoldyn_shared -ltiff
*/


int main(int argc, char* argv[])
{
    simptr  s;
    double  lbounds[2];
    double  hbounds[2];
    double  params[10];
    const char*   species[1] = {"ATP"};
	enum MolecState states[1] = {MSsoln};
        
    lbounds[0] = -50.0;
    lbounds[1] = -50.0;
    hbounds[0] = 50.0;
    hbounds[1] = 50.0;
    
    s = smolNewSim(2,lbounds,hbounds);

	smolSetRandomSeed(s,1);
    smolSetSimTimes(s, 0.0, 250.0, 0.01);
    
    smolSetPartitions(s, "molperbox", 4);
    smolSetPartitions(s, "boxsize", 12.5);
    
    smolAddSpecies(s, "ACA",  "");
    smolAddSpecies(s, "ATP",  "");
    smolAddSpecies(s, "cAMP", "");
    smolAddSpecies(s, "cAR1", "");
    
    smolSetSpeciesMobility(s, "ACA", MSall, 1, 0, 0);
    smolSetSpeciesMobility(s, "ATP", MSall, 1, 0, 0);
    smolSetSpeciesMobility(s, "cAMP", MSall, 1, 0, 0);
    smolSetSpeciesMobility(s, "cAR1", MSall, 1, 0, 0);
    
    
    smolAddSurface(s, "Membrane00");
    smolSetSurfaceAction(s, "Membrane00", PFboth, "ATP", MSsoln, SAreflect);
    params[0] = -20.0;
    params[1] = 20.0;
    params[2] = 10.0;
    params[3] = 20.0;
    params[4] = 20.0;
    smolAddPanel(s, "Membrane00", PSsph, "", "", params);
    
    smolAddCompartment(s, "Cell00");
    smolAddCompartmentSurface(s, "Cell00", "Membrane00");
    smolAddCompartmentPoint(s, "Cell00", params);
    
    smolAddSurfaceMolecules(s, "ACA", MSdown, 30, "Membrane00", PSall, "all", 0);
    smolAddSurfaceMolecules(s, "cAR1", MSup, 30, "Membrane00", PSall, "all", 0);

    smolAddReaction(s, "r100", "", MSall, "", MSall, 1,  species, states, 0.02);
    smolSetReactionRegion(s, "r100", "Cell00", "");
    
	smolUpdateSim(s);
    smolDisplaySim(s);
    smolRunSim(s);
    smolFreeSim(s);
	return 0;
}