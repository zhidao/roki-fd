/* RoKiFD - Robot Forward Dynamics library
 * Copyright (C) 1998 Tomomichi Sugihara (Zhidao)
 *
 * rkfd_solver - contact force computation solver
 * contributer: 2014-2018 Naoki Wakisaka
 */

#include <roki-fd/rkfd_solver.h>

void rkFDSolverInit(rkFDSolver *solver)
{
  solver->prp = NULL;
  solver->com = NULL;

  solver->t     = 0;
  solver->fdprp = NULL;
  solver->cd    = NULL;
  zArrayInit( &solver->chains );
}

void rkFDSolverReset(rkFDSolver *solver)
{
  if( solver->prp )
    zFree( solver->prp );
  solver->prp = NULL;
  solver->com = NULL;
}

void rkFDSolverDestroy(rkFDSolver *solver)
{
  rkFDSolverReset( solver );
  zArrayFree( &solver->chains );
  rkFDSolverInit( solver );
}
