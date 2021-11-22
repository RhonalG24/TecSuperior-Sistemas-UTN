
/*

TAD

    punto2D.h

        typedef struct {
            float x;
            float y;
        } punto2D;
        punto2D crearPunto(int,
        int);
        float distancia(punto2D,
        punto2D);

    punto2D.cpp

        #include “punto2D.h”
        punto2D crearPunto(int X, int Y){
            punto2D punto;
            punto.x = x;
            punto.y = y;
            return punto;
        }
        float distancia(punto2D p1, punto2D p2){
            float d = sqrt( pow(p2.x-p1.x, 2) +
            pow(p2.y-p1.y, 2) );
            return d;
        }

    main.cpp

        #include “punto2D.h”
        punto2D p1;
        punto2D p2;
        p1 = crearPunto(1,2);
        p2 = crearPunto(1,2);
        cout << distancia(p1,
        p2) << endl;

    
*/