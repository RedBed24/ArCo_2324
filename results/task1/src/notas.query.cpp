#include <CL/sycl.hpp>
#include <sycl/ext/intel/fpga_extensions.hpp>


// This allow us to remove cl::sycl:: from all invokations
using namespace cl::sycl;

int main() {
    //queue q{host_selector{}};
    gpu_selector selector;

    queue q(selector);

    std::cout << "Device: " << q.get_device().get_info<info::device::name>()<< std::endl;

//	// host code
//    SIZE = 16;
//    array data;
//    buffer B{data};
//
//    queue q{};
//
//    // Directed Aciclic Graph
//
//	// end host code
//
//    auto task1 = q.submit([&](handler& ) {
//	    // aquí va el comando del grupo
//	    // se usan dos catergorías de código
//	    // - una acción: copy, memset, parallel_for, single_task
//	    // - Host code: crear dependecnias, buffers, accessors...
//	    // sólo una acción puede ser invocada
//	    // Aquí se configura la tarea, lo que se ejecutará
//	    accessor acc{B, h, write_only};
//	    // puede hacer varios accesos a buffs
//
//	    // se puede usar un for normal
//	    h.parallel_for(size, [=](auto& idx) {
//		    // aquí va el código del device
//		    // lo que se va a paralelizar
//		    acc[idx] = idx;
//		});
//	});
//
//    task1.wait()
//
//    q.submit(handler... {
//	    h.depends_on((task1, task2));
//
//	    h.parallel_for(...);
//    });
//
//
//	// el orden por defecto es Out-Of-Order
//	// explicit dependencias por eventos (task1)
//	// implicit dependencias por accesos
//
//	// Unified Shared Memory
//
//	// antes de enviar el kernel, los datos deben de estar en mem
//	// mem device sólo accesible por dev (`malloc_device<int>`)
//	// mem host accesible por ambos, localizada en host
//	// mem shared accesible por ambos, localizada en host o dev, se va moviendo
//
//	// es el free de la libreria
//	free(malloc_host, q);
//
//	// a los buffers se debe acceder mediante un acceso
//
//	host_accesor host_accesor(B);

    return 0;
}

