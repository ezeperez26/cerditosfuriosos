#ifndef _VENTANA_DISENIADOR_H_
#define _VENTANA_DISENIADOR_H_

#include <gtkmm/window.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/filechooserdialog.h>
#include <gtkmm/stock.h>
#include <gtkmm/filefilter.h>

#include "PanelNivel.h"
#include "PanelMundo.h"
#include "PanelEscenario.h"

/**
 * Ventana principal de la aplicacion diseniador.
 */
class VentanaDiseniador : public Gtk::Window, public InformableSeleccion {
	public:
	
		/**
		 * Constructor.
		 */
		VentanaDiseniador();
		
		/**
		 * Destructor.
		 */
		virtual ~VentanaDiseniador();
		
		virtual void editarMundo(std::string rutaMundo);
		
		virtual void nombreSeleccionadoInvalido();
		
		virtual void crearNivel();
		
		virtual std::string seleccionarImagen();
		
	private:
	
		PanelMundo* panelMundo;
		PanelNivel* panelNivel;
		PanelEscenario* panelEscenario;
};

#endif