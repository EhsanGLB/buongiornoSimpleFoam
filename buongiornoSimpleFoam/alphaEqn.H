{
    volScalarField DBEff
    (
        "DBEff",
        DB + turbulence->nut()/Sct
    );

    DBEff.correctBoundaryConditions();

    fvScalarMatrix alphaEqn
    (
        fvm::div(phi, alpha)
      - fvm::laplacian(DBEff, alpha)
      - fvc::laplacian(DT/T, T)
    );

    alphaEqn.relax();
    alphaEqn.solve();
}
