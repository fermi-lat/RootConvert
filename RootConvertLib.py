# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/RootConvert/RootConvertLib.py,v 1.3 2009/01/23 00:21:01 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['RootConvert'])
    env.Tool('EventLib')
    env.Tool('LdfEventLib')
    env.Tool('OnboardFilterTdsLib')
    env.Tool('addLibrary', library = env['obfLibs'])
    env.Tool('addLibrary', library = env['rootLibs'])
    env.Tool('addLibrary', library = env['gaudiLibs'])
    env.Tool('reconRootDataLib')
    env.Tool('digiRootDataLib')
    env.Tool('mcRootDataLib')
    env.Tool('commonRootDataLib')
    env.Tool('gcrSelectRootDataLib')
    env.Tool('AncillaryDataEventLib')
def exists(env):
    return 1;
