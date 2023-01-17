//
//  History.cpp
//  CS32 P1
//
//  Created by Charles Qin on 1/13/23.
//

#include "globals.h"
#include "History.h"
#include <iostream>

History::History(int nRows, int nCols){
    m_rows = nRows;
    m_cols = nCols;
    for (int i = 0; i < m_rows; i++){
        for (int j = 0; j < m_cols; j++)
            m_grid[i][j] = '.';
    }
    
};
    
bool History::record(int r, int c){
        if(r < 1 || c < 1 || r > m_rows || r > m_cols) return false;
        else {
            r-= 1;
            c-= 1;
            switch (m_grid[r][c])
            {
              case '.':  m_grid[r][c] = 'A'; break;
              case 'Z':  break;
              default:   m_grid[r][c]++; break;
            }
            
            return true;
        }
        
    };

void History::display() const {
    clearScreen();
    for (int i = 0; i < m_rows; i++){
        for (int j = 0; j < m_cols; j++)
            std::cout << m_grid[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
};

