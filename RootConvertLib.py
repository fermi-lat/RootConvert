# $Header: /nfs/slac/g/glast/ground/cvs/RootConvert/RootConvertLib.py,v 1.4 2009/11/12 01:04:07 jrb Exp $
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
