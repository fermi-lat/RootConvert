# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/RootConvert/SConscript,v 1.3 2008/10/27 17:15:08 ecephas Exp $
# Authors: David Chamont <chamont@poly.in2p3.fr>, Heather Kelly <heather@slac.stanford.edu>
# Version: RootConvert-01-42-00
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('RootConvertLib', depsOnly = 1)

RootConvert = libEnv.SharedLibrary('RootConvert', listFiles(['src/Utilities/*.cxx','src/MonteCarlo/*.cxx',
							     'src/Digi/*.cxx','src/Recon/AcdReconConvert.cxx',
							     'src/Recon/AdfReconConvert.cxx',
							     'src/Recon/CalClusterConvert.cxx',
							     'src/Recon/CalEventEnergyConvert.cxx',
							     'src/Recon/CalMipTrackConvert.cxx',
							     'src/Recon/CalParamsConvert.cxx',
							     'src/Recon/CalXtalRecDataConvert.cxx',
							     'src/Recon/GcrTrackConvert.cxx',
							     'src/Recon/GcrXtalConvert.cxx',
							     'src/GcrSelect/*.cxx']))


if baseEnv['PLATFORM'] == 'win32':
	progEnv.AppendUnique(CPPDEFINES = ['GLEAM', '__i386', 'EFC_FILTER', '_WIN32'])

progEnv.Tool('RootConvertLib')
test_RootConvert = progEnv.Program('test_RootConvert', ['src/test/test_RootConvert.cxx'])

progEnv.Tool('registerObjects', package = 'RootConvert', libraries = [RootConvert], testApps = [test_RootConvert], includes = listFiles(['RootConvert/*'], recursive = True))




