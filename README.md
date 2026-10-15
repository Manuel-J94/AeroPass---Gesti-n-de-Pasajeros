AeroPass — Sistema de Gestión de Pasajeros y Ventas de Boletos
Versión de referencia: v0.1-beta
Estado: prototipo de consola en C++ con documentación y planificación del proyecto
Enfoque de desarrollo: Scrumban
Arquitectura seleccionada: arquitectura por capas con patrón MVC en presentación
Repositorio indicado en el tablero: https://github.com/Manuel-J94/AeroPass---Gesti-n-de-Pasajeros
1. Objetivo y problema
AeroPass busca gestionar la venta de boletos de avión en tres clases —Primera, Segunda y Tercera—, asignar asientos, controlar ocupación y mostrar ingresos estimados. La problemática identificada en el análisis es que el control manual mediante hojas de cálculo puede provocar errores de asignación y sobreventa, y dificulta consultar rápidamente ocupación, ventas y reportes diarios.
2. Funcionalidades del prototipo
- Vender boletos en tres clases de servicio.
- Asignar automáticamente el primer asiento disponible de la clase elegida.
- Registrar nombre del pasajero, clase y asiento en memoria.
- Listar pasajeros por clase.
- Mostrar estadísticas de ocupación e ingresos estimados.
- Validar disponibilidad antes de realizar una venta.
La distribución de capacidad definida es 15 % para Primera, 25 % para Segunda y 60 % para Tercera clase.
3. Requisitos documentados
Requisitos funcionales
- RF-01: asignar automáticamente el primer asiento disponible en la clase seleccionada.
- RF-02: mostrar estadísticas de ocupación por clase y total.
- RF-03: validar que el nombre del pasajero no esté vacío ni contenga números.
- RF-04: permitir exportar reportes a TXT o CSV.
- RF-05: listar pasajeros con número de asiento y clase.
Requisitos no funcionales
- RNF-01: responder en menos de 2 segundos a las acciones del usuario.
- RNF-02: ser portable y ejecutarse desde una carpeta o USB sin instalación.
- RNF-03: permitir que un usuario sin experiencia venda un boleto en menos de 3 minutos.
- RNF-04: manejar entradas inválidas sin cerrar inesperadamente el programa.
- RNF-05: mantener el código documentado y con nomenclatura descriptiva.
4. Arquitectura y separación frontend/backend
La decisión documentada es una arquitectura por capas con MVC en la presentación:
- Presentación: interfaz de usuario y controladores de venta, reportes y pasajeros.
- Lógica de negocio: gestores que aplican reglas de venta, validación y estadísticas.
- Acceso a datos: repositorios para guardar, buscar y listar información.
- Servicios: autenticación, manejo de errores y exportación.
- Base de datos: persistencia de vuelos, pasajeros, asientos y usuarios.
Frontend
En la versión actual, la interacción se realiza por consola. Para una futura versión gráfica/web, el frontend presentaría formularios, selección de asientos, listados y reportes. Los controladores gestionarían los eventos de la interfaz.
Backend
La lógica de negocio debe encargarse de validar datos, comprobar disponibilidad, asignar asientos, registrar ventas y calcular estadísticas. Los repositorios se ocuparían de leer y guardar datos.
Comunicación propuesta
Para una futura versión web, la interfaz se comunicaría con un backend mediante solicitudes HTTP a una API, intercambiando datos JSON. Esta API y la persistencia aún se consideran evolución futura: no deben describirse como funciones ya implementadas en el prototipo de consola.
5. Modelado y análisis realizados
La documentación de la asignatura incluye:
- Técnica de levantamiento de información y hallazgos de usuario.
- Historias de usuario y matriz de trazabilidad.
- Cinco requisitos funcionales y cinco no funcionales.
- Diagrama de casos de uso.
- Diagrama de clases.
- Diagrama de secuencia para la venta de boleto.
- Diagrama de actividades para la venta de boleto.
- Decisión arquitectónica y componentes de la arquitectura por capas con MVC.
Enlaces de Visual Paradigm compartidos en los documentos:
- Casos de uso: https://online.visual-paradigm.com/share.jsp?id=343730353730382d32
- Clases: https://online.visual-paradigm.com/share.jsp?id=343730353730382d33
- Secuencia: https://online.visual-paradigm.com/share.jsp?id=343730353730382d34
- Actividades: https://online.visual-paradigm.com/share.jsp?id=343730353730382d35
6. Registro de cinco avances
1. Análisis de necesidades: se identificó el problema del control manual de asientos y la necesidad de consultar ocupación, ingresos y reportes.
2. Requisitos: se documentaron cinco requisitos funcionales y cinco no funcionales con criterios de aceptación.
3. Modelado UML: se prepararon casos de uso, clases, secuencia y actividades.
4. Diseño arquitectónico: se seleccionó arquitectura por capas con MVC y separación de responsabilidades.
5. Planificación y riesgos: se organizó el trabajo con Scrumban, prioridades, fechas, estados y una matriz de riesgos.
Estos son avances documentados de la asignatura; no significan que cada uno corresponda a un commit independiente en Git.
7. Estado del tablero de GitHub Projects
La captura compartida del tablero muestra las siguientes tarjetas y estados actuales visibles:
Estado	Tarjetas visibles
Backlog	#10 Definición de arquitectura inicial
To do	#4 Refactorizar código y mejorar clases/aplicar SOLID
In progress	#1 Persistencia en archivos; #2 Mejorar menú; #3 Interfaz gráfica (prototipo)
Ready	#7 Asignación automática de asientos; #8 Estadísticas en tiempo real
Done	#6 Reportes mejorados y exportación TXT/CSV; #5 Validar entradas; #9 Menú intuitivo y guiado


Estos estados se transcriben de la captura compartida. El tablero presenta cinco columnas: Backlog, To do, In progress, Ready y Done. Verifica que los estados sigan siendo los mismos antes de entregar el trabajo.
8. Cuatro Issues reales visibles en GitHub
La captura del tablero permite identificar los Issues existentes por número. Para la entrega se pueden documentar estos cuatro:
1. Issue #1 — Persistencia en archivos: guardar los datos en un archivo .dat o .json para evitar perderlos al cerrar el programa. Estado en la captura: In progress.
2. Issue #2 — Mejorar el menú: hacer el menú más intuitivo, con colores y mensajes de ayuda para el usuario. Estado en la captura: In progress.
3. Issue #3 — Interfaz gráfica (prototipo): preparar un prototipo en Qt o HTML para seleccionar asientos visualmente. Estado en la captura: In progress.
4. Issue #4 — Refactorizar código: corregir nombres mal escritos y mejorar las clases/aplicar SOLID. Estado en la captura: To do.
Los números y títulos anteriores se transcriben de la captura del GitHub Projects compartida. Para cumplir con la evidencia de Issues, abre cada Issue en la pestaña Issues del repositorio y toma una captura donde se vean sus detalles.
9. Matriz resumida de riesgos
Riesgo	Probabilidad	Impacto	Respuesta documentada
Falta de tiempo para completar tareas	Alta	Alto	Priorizar refactorización y validación; usar el tablero diariamente.
Errores en validación de entradas	Media	Alto	Probar casos extremos y revisar antes de cerrar tareas.
Cambios de requisitos de última hora	Media	Medio	Mantener el backlog y ajustar prioridades y fechas.
Pérdida de datos por falta de persistencia	Baja	Alto	Implementar persistencia y mantener respaldos/capturas del código.
