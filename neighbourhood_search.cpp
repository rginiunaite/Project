#include "Aboria.h"
#include <random>
#include <map>

using namespace Aboria;


/* int main() {
	    /*
	     * 3D domain with a few randomly placed particles
	     */
	
	/*const size_t N = 100;

	typedef Particles<> particle_type;
	typedef particle_type::position position;
	particle_type particles(N);
	std::default_random_engine gen;
	std::uniform_real_distribution<double> uniform(-1,1);
	for (int i=0; i<N; ++i) {
	    get<position>(particles)[i] = vdouble3(uniform(gen),uniform(gen),uniform(gen));
	}
	 
	// Initialise the domain

	vdouble3 min(-1);
	vdouble3 max(1);
	vbool3 periodic(true);
	particles.init_neighbour_search(min,max,periodic);

	// particles within a distance radius of the point (0,0,0)

	double radius = 1;
	int count = 0;
	for (const auto& i: euclidean_search(particles.get_query(),vdouble3(0),radius)) {
	    count++;
	}
	std::cout << "There are "<< count << " particles.\n";


	vtkWriteGrid("neighbours",0,particles.get_grid(true));

}

*/

int main() {





	    /*
	     * 2D domain with a few randomly placed particles
	     */

	const size_t N = 100;
	//ABORIA_VARIABLE(velocity,vdouble2,"velocity")
	typedef Particles<std::tuple<>, 2> particle_type;
	//typedef Particles<std::tuple<>,2,std::vector,bucket_search_serial> particle_type;
	typedef particle_type::position position;
	particle_type particles(N);
	std::default_random_engine gen;
	std::uniform_real_distribution<double> uniform(-1,1);
	for (int i=0; i<N; ++i) {
	    get<position>(particles)[i] = vdouble2(uniform(gen),uniform(gen));
	}
	 
	// Initialise the domain

	vdouble2 min(-1);
	vdouble2 max(1);
	vbool2 periodic(true);
	particles.init_neighbour_search(min,max,periodic);

	// particles within a distance radius of the point (0,0,0)

	/*double radius = 0.5;
	int count = 0;
	for (const auto& i: euclidean_search(particles.get_query(),vdouble2(0),radius)) {
	    count++;
	}
	std::cout << "There are "<< count << " particles.\n";*/


	// finds coordinates that are close to (0,0)
	/*for (const auto& i: euclidean_search(particles.get_query(),vdouble2(0),radius)) {
   		particle_type::const_reference b = std::get<0>(i);
    		const vdouble2& dx = std::get<1>(i);
    		std::cout << "Found a particle with dx = " << dx << " and id = " << get<id>(b) << "\n";
	}*/


	// prints all the positions of particles
	/*for (int i=0;i<N; i++){
		std::cout << "the particle is at position "<< get<position>(particles)[i] << std::endl;
	}*/

	// moves all the particles in random x and y directions
	/*for (auto& x: get<position>(particles)) {
	    x += vdouble2(uniform(gen),uniform(gen));
	}
	particles.update_positions();
	*/

	// updates position of one of the particles 
	get<position>(particles)[4] = vdouble2(0.1,0);
	particles.update_positions(particles.begin()+4,particles.begin()+5);

	// deletes all the particles with an x coordinate less than 0.5

	for (auto p: particles) {
	    if (get<position>(p)[0] < 0.2) {
		get<alive>(p) = false;
	    }
	}
	particles.update_positions();

	// deletes the last particle
	//get<alive>(particles)[N-1] = false;
	//particles.update_positions(particles.begin()+N-1,particles.end();

	// prints all the positions after the update 
	/*for (int i=0;i<N; i++){
		
		std::cout << "the particle is at new position "<< get<position>(particles)[i] << std::endl;
	}*/
	// saves the file
	vtkWriteGrid("neighbours",0,particles.get_grid(true));

}
