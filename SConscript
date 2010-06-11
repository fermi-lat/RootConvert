# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/RootConvert/SConscript,v 1.13 2010/05/17 01:38:48 usher Exp $
# Authors: David Chamont <chamont@poly.in2p3.fr>, Heather Kelly <heather@slac.stanford.edu>
# Version: RootConvert-01-46-00
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='RootConvert', toBuild='shared')

RootConvert=libEnv.SharedLibrary('RootConvert',
                                 listFiles(['src/Utilities/*.cxx',
                                            'src/MonteCarlo/*.cxx',
                                            'src/Digi/*.cxx',
                                            'src/Recon/Acd*.cxx',
                                            'src/Recon/Adf*.cxx',
                                            'src/Recon/Cal*.cxx',
                                            'src/Recon/Gcr*.cxx',
                                            'src/GcrSelect/*.cxx']))

if baseEnv['PLATFORM'] == 'win32':
	progEnv.AppendUnique(CPPDEFINES = ['GLEAM', '__i386', 'EFC_FILTER',
                                           '_WIN32'])

progEnv.Tool('RootConvertLib')
test_RootConvert = progEnv.Program('test_RootConvert',
                                   ['src/test/test_RootConvert.cxx'])

progEnv.Tool('registerTargets', package = 'RootConvert',
             libraryCxts = [[RootConvert, libEnv]],
             testAppCxts = [[test_RootConvert, progEnv]],
             includes = listFiles(['RootConvert/*'], recursive = True))




