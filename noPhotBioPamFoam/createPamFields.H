
Info << "  Reading field SS (Readily biodegradable substrate)" << endl;
volScalarField SS
(
    IOobject
    (
        "SS",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info << "  Reading field SAC (acetate COD)" << endl;
volScalarField SAC
(
    IOobject
    (
        "SAC",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info << "   Reading H2" << endl;
volScalarField SH2
(
    IOobject
    (
        "SH2",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info << "    Reading SIC" << endl;
volScalarField SIC
(
    IOobject
    (
        "SIC",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info << "  Reading field XS (slowly biodegradable substrate)" << endl;
volScalarField XS
(
    IOobject
    (
        "XS",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info << "  Reading field XPB (photoheterotrophic biomass)" << endl;
volScalarField XPB
(
    IOobject
    (
        "XPB",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info << "  Reading field XI (inert solid organic matter)" << endl;
volScalarField XI
(
    IOobject
    (
        "XI",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info << "  Reading field SIN (inorganic nitrogen)" << endl;
volScalarField SIN
(
    IOobject
    (
        "SIN",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info << "  Reading field SIP (inorganic phosphorus)" << endl;
volScalarField SIP
(
    IOobject
    (
        "SIP",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info << "  Reading field SI (soluble inert organic matter)" << endl;
volScalarField SI
(
    IOobject
    (
        "SI",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField G850
(
    IOobject
    (
        "G850",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("G850", dimensionSet(1,0,-3,0,0,0,0),0)
);



Info << "Creating scalar fields for process rates" << endl;

volScalarField rhoAcetateUptake
(
    IOobject
    (
        "rhoAcetateUptake",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("rhoAcetateUptake", dimMass/dimVolume/dimTime, 0)
);

volScalarField rhoPhotoheterotrophicUptake
(
    IOobject
    (
        "rhoPhotoheterotrophicUptake",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("rhoPhotoheterotrophicUptake", dimMass/dimVolume/dimTime, 0)
);

volScalarField rhoChemoheterotrophicUptake
(
    IOobject
    (
        "rhoChemoheterotrophicUptake",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("rhoChemoheterotrophicUptake", dimMass/dimVolume/dimTime, 0)
);

volScalarField rhoAutotrophicUptake
(
    IOobject
    (
        "rhoAutotrophicUptake",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar
    (
        "rhoAutotrophicUptake",
        dimensionSet(0,-3,-1,0,1,0,0),
        scalar(0.0)
    )
);

volScalarField rhoDecay
(
    IOobject
    (
        "rhoDecay",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("rhoDecay", dimMass/dimVolume/dimTime, 0)
);

volScalarField rhoHydrolysis
(
    IOobject
    (
        "rhoHydrolysis",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("rhoHydrolysis", dimMass/dimVolume/dimTime, 0)
);


Info << "Creating scalar fields for species diffusivities" << endl;

volScalarField DSS
(
    IOobject
    (
        "DSS",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    DSSValue
);

volScalarField DSAC
(
    IOobject
    (
        "DSAC",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    DSACValue
);

volScalarField DSH2
(
    IOobject
    (
        "DSH2",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    DSH2Value
);

volScalarField DSIC
(
    IOobject
    (
        "DSIC",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    DSICValue
);

volScalarField DXS
(
    IOobject
    (
        "DXS",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    DXSValue
);

volScalarField DXPB
(
    IOobject
    (
        "DXPB",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    DXPBValue
);

volScalarField DSIN
(
    IOobject
    (
        "DSIN",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    DSINValue
);

volScalarField DSIP
(
    IOobject
    (
        "DSIP",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    DSIPValue
);

volScalarField DSI
(
    IOobject
    (
        "DSI",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    DSIValue
);

volScalarField DXI
(
    IOobject
    (
        "DXI",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
    DXIValue
);


Info << "Creating scalar field for dissipation function" << endl;

volScalarField dissipationCoeff
(
    IOobject
    (
        "dissipationCoeff",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("dissipationCoeff", dimless/dimTime, 0)
);

//======================================================================
// Temporary: Write out limitation fields

volScalarField inhibFA
(
    IOobject
    (
        "inhibFA",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("inhibFA", dimless, 0)
);

volScalarField limitingSAC
(
    IOobject
    (
        "limitingSAC",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("limitingSAC", dimless, 0)
);

volScalarField limitingSS
(
    IOobject
    (
        "limitingSS",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("limitingSS", dimless, 0)

);

volScalarField limitingSIC
(
    IOobject
    (
        "limitingSIC",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("limitingSIC", dimless, 0)
);

volScalarField limitingSH2
(
    IOobject
    (
        "limitingSH2",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("limitingSH2", dimless, 0)
);

volScalarField limitingSIN
(
    IOobject
    (
        "limitingSIN",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("limitingSIN", dimless, 0)
);

volScalarField limitingSIP
(
    IOobject
    (
        "limitingSIP",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("limitingSIP", dimless, 0)
);


volScalarField limitingG
(
    IOobject
    (
        "limitingG",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("limitingG", dimless, 0)
);

Info << endl;
