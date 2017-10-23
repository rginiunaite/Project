#include "Aboria.h"

using namespace Aboria;


int main() {
    /*
     * Create a 2d particle container type with one
     * additional variable "velocity", represented
     * by a 2d double vector
     */
    ABORIA_VARIABLE(velocity,vdouble2,"velocity")
    //ABORIA_VARIABLE(alive,bool,"alive") // nesamone, kaip sita sutvarkyti????
    typedef Particles<std::tuple<velocity>,2> container_type;
    typedef typename container_type::position position;
    //typedef typename container_type::alive alive; // why do I need position as above but not alive !!!!

    /*
     * create a particle set with size N
     */
    const int N = 100;
    container_type particles(N);

    container_type more_particles(4); 

	for (int i =0;i<4;++i){
		get<velocity>(more_particles)[i] = vdouble2(10,10);
	}
	
	container_type::value_type p; // WHY DO I NEED VALUE_TYPE HERE?

	get<velocity>(p) = 1;
	
    std::uniform_real_distribution<double> uni(0,1);
    std::default_random_engine gen;
    for (int i = 0; i < N; ++i) {
        /*
         * set a random position, and initialise velocity
         */
        get<position>(particles)[i] = vdouble2(uni(gen),uni(gen));
        get<velocity>(particles)[i] = vdouble2(1,1);
	get<alive>(particles)[i] = true;
    }

    std::cout << "velocity of new particle is variable equals "<< get<velocity>(more_particles)[2] << std::endl;
    std::cout << "the particle position is "<< get<position>(particles)[5] << std::endl;
    std:cout << "the particle id is "<< get<id>(particles)[5] << std::endl;
    std::cout << "the particle velocity is "<< get<velocity>(particles)[5] << std::endl;
    std::cout << "the particle is "<< get<alive>(particles)[5] << std::endl; // I GET THAT LITTLE MATRIX, BECAUSE ALIVE WAS NOT SOMEHOW INITIALISED

	//particles.push_back(p); // cannot do this because:
/* Assertion `new_n == 0 || (update_end==end && update_end-update_begin>=new_n)` failed in /home/giniunaite/Aboria/src/NeighbourSearchBase.h line 462: detected 101 new particles, which are not covered by update range
Trace/breakpoint trap (core dumped)
*/

/*for (int i=0; i < particles.size(); i++) {
   std::cout << "Accessing particle with id = " << get<id>(particles[i]) << "\n";
}*/



std::vector<size_t>& ids = get<id>(particles);


    /*
     * write particle container to a vtk
     * unstructured grid file
     */
    vtkWriteGrid("learn_aboria",0,particles.get_grid(true));

}
