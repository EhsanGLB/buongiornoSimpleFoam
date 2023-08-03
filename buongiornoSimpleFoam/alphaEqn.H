{
    volScalarField DbEff
    (
        "DbEff",
        Db + turbulence->nut()/Sct
    );

    DbEff.correctBoundaryConditions();

    fvScalarMatrix alphaEqn
    (
        fvm::div(phi, alpha)
      - fvm::laplacian(DbEff, alpha)
      - fvc::laplacian(DT/T, T)
    );

    alphaEqn.relax();
    alphaEqn.solve();
}